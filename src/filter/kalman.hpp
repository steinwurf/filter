// Copyright (c) Steinwurf ApS 2018.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.


#pragma once

#include <algorithm>
#include <cassert>
#include <limits>

namespace score
{
/// Implements a simple Kalman filter variatn that can be used to estimate
/// a value based on some samples
template<typename EstimateType, typename GainType = float>
class kalman_filter
{

public:

    /// constructor
    /// @param gain the initial Kalman gain
    /// @param initial_estimate the initial estimation value
    kalman_filter(GainType gain, EstimateType initial_estimate = 0) :
        m_estimate(initial_estimate)
    {
        set_gain(gain);
    }

    /// add a new asmples
    /// @param value a sample value
    void sample(EstimateType value)
    {
        m_estimate = (EstimateType)(value * m_gain + m_estimate * (1 - m_gain));
        m_estimate = std::min(m_estimate, m_max_estimate);
        m_estimate = std::max(m_estimate, m_min_estimate);
    }

    /// get the current estimation
    /// @return the current value estimate
    EstimateType estimate() const
    {
        return m_estimate;
    }

    /// set the Kalman gain
    /// @param gain the Kalman gain
    void set_gain(GainType gain)
    {
        assert(0 < gain);
        assert(gain <= 1);

        m_gain = gain;
    }

    /// the Kalman filter gain
    /// @return the Kalman filter gain
    GainType gain() const
    {
        return m_gain;
    }

    /// set the minimum value the estimation is allowed to take
    /// @param min the minimum value of the estimation
    void set_min_estimate(EstimateType min)
    {
        assert(min < m_max_estimate);
        m_min_estimate = min;
    }

    /// the minimum value the estimation is allowed to take
    /// @return the minimum value the estimation is allowed to take
    EstimateType min_estimate() const
    {
        return m_min_estimate;
    }

    /// set the maximum value the estimation is allowed to take
    /// @param max the minimum value of the estimation
    void set_max_estimate(EstimateType max)
    {
        assert(max > m_min_estimate);
        m_max_estimate = max;
    }

    /// the maximum value the estimation is allowed to take
    /// @return the maximum value the estimation is allowed to take
    EstimateType max_estimate() const
    {
        return m_max_estimate;
    }

private:

    /// The gain of the kalman filter often denoted K
    GainType m_gain;

    /// The current estimate fo the value
    EstimateType m_estimate;

    /// The min value the estimate is allowed to take
    EstimateType m_min_estimate = std::numeric_limits<EstimateType>::min();

    /// The max value the estimate is allowed to take
    EstimateType m_max_estimate = std::numeric_limits<EstimateType>::max();
};
}
