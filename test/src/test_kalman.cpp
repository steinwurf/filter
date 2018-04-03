// Copyright (c) Steinwurf ApS 2018.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <filter/kalman.hpp>

#include <gtest/gtest.h>

TEST(test_kalman, float)
{
    filter::kalman<float> estimator(.2f);

    std::vector<float> samples = {1.f, 1.f, 0.f};
    std::vector<float> estimates = {.2f, .36f, .288f};

    ASSERT_EQ(samples.size(), estimates.size());

    for (uint32_t i = 0; i < samples.size(); i++)
    {
        estimator.sample(samples[i]);
        EXPECT_FLOAT_EQ(estimates[i], estimator.estimate());
    }
}

TEST(test_kalman, int)
{
    filter::kalman<int16_t> estimator(0.5);

    std::vector<int16_t> samples = {1, 1, 100,100, 0};
    std::vector<int16_t> estimates = {0, 0, 50, 75, 37};

    ASSERT_EQ(samples.size(), estimates.size());

    for (uint32_t i = 0; i < samples.size(); i++)
    {
        estimator.sample(samples[i]);
        EXPECT_EQ(estimates[i], estimator.estimate());
    }
}

TEST(test_kalman, min_max)
{
    filter::kalman<int16_t> estimator(1);

    estimator.set_min_estimate(0);
    estimator.set_max_estimate(10);

    std::vector<int16_t> samples = {-1000, -1000, 1000, 0};
    std::vector<int16_t> estimates = {0, 0, 10, 0};

    ASSERT_EQ(samples.size(), estimates.size());

    for (uint32_t i = 0; i < samples.size(); i++)
    {
        estimator.sample(samples[i]);
        EXPECT_EQ(estimates[i], estimator.estimate());
    }
}


TEST(test_kalman_filter, getters_and_setters)
{
    filter::kalman<int16_t> estimator(1);

    {
        int16_t min_estimate = 1;
        estimator.set_min_estimate(min_estimate);
        EXPECT_EQ(min_estimate, estimator.min_estimate());

    }
    {
        int16_t max_estimate = 2;
        estimator.set_max_estimate(max_estimate);
        EXPECT_EQ(max_estimate, estimator.max_estimate());

    }
    {
        float gain = 0.7f;
        estimator.set_gain(gain);
        EXPECT_EQ(gain, estimator.gain());

    }
}
