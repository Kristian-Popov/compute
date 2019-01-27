//---------------------------------------------------------------------------//
// Copyright (c) 2019 Kristian Popov <kristian.popov@outlook.com>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
// See http://boostorg.github.com/compute for more information.
//---------------------------------------------------------------------------//
#ifndef BOOST_COMPUTE_EXCEPTION_FUTURE_ERROR_HPP
#define BOOST_COMPUTE_EXCEPTION_FUTURE_ERROR_HPP

#include <string>

#include <boost/compute/exception/opencl_error.hpp>

namespace boost {
namespace compute {

/// \class future_error
/// \brief Defines an exception object that is thrown on future failures.
class future_error : public std::exception
{
public:
    /// Creates a new future_error exception object with \p error_message
    explicit future_error(const std::string& error_message) throw()
        : m_error_message(error_message)
    {
    }

    /// Creates a new future_error exception object with \p error_message
    explicit future_error(const char* error_message) throw()
        : m_error_message(error_message)
    {
    }

    /// Returns a string with a description of the error.
    virtual const char* what() const throw()
    {
        return m_error_message.c_str();
    }

    /// Destroys the future error object.
    ~future_error() throw()
    {
    }

private:
    std::string m_error_message;
};

} // end compute namespace
} // end boost namespace

#endif // BOOST_COMPUTE_EXCEPTION_FUTURE_ERROR_HPP
