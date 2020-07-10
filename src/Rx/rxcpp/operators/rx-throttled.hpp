// Copyright (c) Microsoft Open Technologies, Inc. All rights reserved. See License.txt in the project root for license information.

#pragma once

/*! \file rx-throttled.hpp

    \brief For each item from this observable, filter out repeated values and emit only items that have not already been emitted.

    \return Observable that emits those items from the source observable that are throttled.

    \note istinct keeps an unordered_set<T> of past values. Due to an issue in multiple implementations of std::hash<T>, rxcpp maintains a whitelist of hashable types. new types can be added by specializing rxcpp::filtered_hash<T>

    \sample
    \snippet throttled.cpp throttled sample
    \snippet output.txt throttled sample
*/

#if !defined(RXCPP_OPERATORS_RX_throttled_HPP)
#define RXCPP_OPERATORS_RX_throttled_HPP

#include "../rx-includes.hpp"

namespace rxcpp {

namespace operators {

namespace detail {

template<class... AN>
struct throttled_invalid_arguments {};

template<class... AN>
struct throttled_invalid : public rxo::operator_base<throttled_invalid_arguments<AN...>> {
    using type = observable<throttled_invalid_arguments<AN...>, throttled_invalid<AN...>>;
};
template<class... AN>
using throttled_invalid_t = typename throttled_invalid<AN...>::type;

template<class T, class Duration>
struct throttled
{
    typedef rxu::decay_t<T> source_value_type;
    typedef rxu::decay_t<Duration> duration_type;

    duration_type period;
    
    throttled(duration_type period)
        : period(period)
    {
    }
    
    template<class Subscriber>
    struct throttled_observer
    {
        typedef throttled_observer<Subscriber> this_type;
        typedef source_value_type value_type;
        typedef rxu::decay_t<Subscriber> dest_type;
        typedef observer<value_type, this_type> observer_type;
        typedef rxsc::scheduler::clock_type::time_point time_type;
        dest_type dest;
        duration_type period;
        mutable rxu::detail::maybe<time_type> remembered;
        
        throttled_observer(dest_type d, duration_type period)
                : dest(d), period(std::move(period))
        {
        }

        void on_next(source_value_type v) const {
            if (remembered.empty() || (identity_current_thread().now() - remembered.get()) > period) {
                dest.on_next(v);
            }
            remembered.reset(identity_current_thread().now());
        }
        
        void on_error(rxu::error_ptr e) const {
            dest.on_error(e);
        }
        void on_completed() const {
            dest.on_completed();
        }

        static subscriber<value_type, observer<value_type, this_type>> make(dest_type d, duration_type p) {
            return make_subscriber<value_type>(d, this_type(d, std::move(p)));
        }
    };

    template<class Subscriber>
    auto operator()(Subscriber dest) const
    -> decltype(throttled_observer<Subscriber>::make(std::move(dest), period)) {
        return      throttled_observer<Subscriber>::make(std::move(dest), period);
    }
};

}

/*! @copydoc rx-throttled.hpp
*/
template<class... AN>
auto throttled(AN&&... an)
    ->      operator_factory<throttled_tag, AN...> {
     return operator_factory<throttled_tag, AN...>(std::make_tuple(std::forward<AN>(an)...));
}

}

template<>
struct member_overload<throttled_tag>
{
    template<class Observable, class Duration,
        class Enabled = rxu::enable_if_all_true_type_t<
            is_observable<Observable>,
            rxu::is_duration<Duration>>,
        class SourceValue = rxu::value_type_t<Observable>,
        class throttled = rxo::detail::throttled<SourceValue, rxu::decay_t<Duration>>>
    static auto member(Observable&& o, Duration&& d)
        -> decltype(o.template lift<SourceValue>(throttled(std::forward<Duration>(d)))) {
        return      o.template lift<SourceValue>(throttled(std::forward<Duration>(d)));
    }
    
    template<class... AN>
    static operators::detail::throttled_invalid_t<AN...> member(const AN&...) {
        std::terminate();
        return {};
        static_assert(sizeof...(AN) == 10000, "throttled takes required Duration");
    }
};

}

#endif
