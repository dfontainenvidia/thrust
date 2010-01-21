/*
 *  Copyright 2008-2009 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*! \file linear_feedback_shift.h
 *  \brief A linear feedback shift pseudorandom number generator.
 */

#pragma once

#include <thrust/detail/config.h>
#include <thrust/random/detail/linear_feedback_shift_engine_wordmask.h>

namespace thrust
{

namespace experimental
{

namespace random
{

template<typename UIntType, int w, int k, int q, int s>
  class linear_feedback_shift_engine
{
  public:
    typedef UIntType result_type;

    static const size_t word_size = w;
    static const size_t exponent1 = k;
    static const size_t exponent2 = q;
    static const size_t step_size = s;

    static const result_type wordmask =
      detail::linear_feedback_shift_engine_wordmask<
        result_type,
        w
      >::value;

    static const result_type min = 0;
    static const result_type max = wordmask;
    static const result_type default_seed = 341u;

    // constructors and seeding functions
    __host__ __device__
    explicit linear_feedback_shift_engine(result_type value = default_seed);

    __host__ __device__
    void seed(result_type value = default_seed);

    // generating functions
    __host__ __device__
    result_type operator()(void);

    __host__ __device__
    void discard(unsigned long long z);

    /*! \cond
     */
  private:
    result_type m_value;
    /*! \endcond
     */
}; // end linear_feedback_shift_engine

} // end random

} // end experimental

} // end thrust

#include <thrust/random/detail/linear_feedback_shift_engine.inl>
