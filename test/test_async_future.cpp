//---------------------------------------------------------------------------//
// Copyright (c) 2019 Kristian Popov <kristian.popov@outlook.com>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
// See http://boostorg.github.com/compute for more information.
//---------------------------------------------------------------------------//

#define BOOST_TEST_MODULE TestFuture
#include <boost/test/unit_test.hpp>

#include <boost/compute/async/future.hpp>
#include <boost/compute/user_event.hpp>

#include "context_setup.hpp"

BOOST_AUTO_TEST_CASE(empty){}

BOOST_AUTO_TEST_CASE(empty_void_future)
{
    boost::compute::future<void> future;
    BOOST_CHECK(!future.valid());
    BOOST_CHECK_THROW(future.wait(), boost::compute::future_error);
    BOOST_CHECK_THROW(future.is_ready(), boost::compute::future_error);
}

BOOST_AUTO_TEST_CASE(empty_int_future)
{
    boost::compute::future<int> future;
    BOOST_CHECK(!future.valid());
    BOOST_CHECK_THROW(future.wait(), boost::compute::future_error);
    BOOST_CHECK_THROW(future.is_ready(), boost::compute::future_error);
}

#ifdef BOOST_COMPUTE_CL_VERSION_1_1
BOOST_AUTO_TEST_CASE(void_future)
{
    REQUIRES_OPENCL_VERSION(1, 1);

    boost::compute::user_event event(context);
    boost::compute::future<void> future(event);
    BOOST_CHECK(future.valid());
    BOOST_CHECK(!future.is_ready());

    event.set_status(CL_COMPLETE);
    BOOST_CHECK_NO_THROW(future.wait());

    BOOST_CHECK(future.is_ready());
}

BOOST_AUTO_TEST_CASE(int_future)
{
    REQUIRES_OPENCL_VERSION(1, 1);

    boost::compute::user_event event(context);
    boost::compute::future<int> future(1, event);
    BOOST_CHECK(future.valid());
    BOOST_CHECK(!future.is_ready());

    event.set_status(CL_COMPLETE);
    BOOST_CHECK_NO_THROW(future.wait());

    BOOST_CHECK(future.is_ready());
}
#endif // BOOST_COMPUTE_CL_VERSION_1_1

BOOST_AUTO_TEST_SUITE_END()
