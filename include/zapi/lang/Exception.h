// Copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by zzu_softboy on 07/06/2017.

#ifndef ZAPI_LANG_EXCEPTION_H
#define ZAPI_LANG_EXCEPTION_H

#include <exception>
#include <string>

#include "zapi/Global.h"

namespace zapi
{
namespace lang
{

class ZAPI_DECL_EXPORT Exception : public std::exception
{
protected:
   /**
    * The exception message
    * @var    char*
    */
   std::string m_message;
public:
   /**
    * Constructor
    *
    * @param  message The exception message
    */
   Exception(std::string message) : m_message(std::move(message))
   {}

   /**
    * Destructor
    */
   virtual ~Exception() = default;

   /**
    * Overridden what method
    * @return const char *
    */
   virtual const char *what() const ZAPI_DECL_NOEXCEPT override
   {
      return m_message.c_str();
   }

   /**
    *  Returns the message of the exception.
    *  @return &string
    */
   const std::string &message() const ZAPI_DECL_NOEXCEPT
   {
      return m_message;
   }

   /**
    * Returns the exception code
    *
    * @return The exception code
    */
   virtual long int code() const ZAPI_DECL_NOEXCEPT
   {
      return -1;
   }

   /**
    * Retrieve the filename the exception was thrown in
    *
    * @note   This only works if the exception was originally
    *         thrown in PHP userland. If the native() member
    *         function returns true, this function will not
    *         be able to correctly provide the filename.
    *
    * @return The filename the exception was thrown in
    */
   virtual const std::string &file() const ZAPI_DECL_NOEXCEPT
   {
      static std::string file{"<filename unknown>"};
      return file;
   }

   /**
    * Retrieve the line at which the exception was thrown
    */
   virtual const long int line() const ZAPI_DECL_NOEXCEPT
   {
      return -1;
   }

   /**
    * Is this a native exception (one that was thrown from C++ code)
    * @return bool
    */
   virtual bool native() const
   {
      return true;
   }

   /**
    * Report this error as a fatal error
    * @return bool
    */
   virtual bool report() const
   {
      return false;
   }
};

} // lang
} // zapi

#endif //ZAPI_LANG_EXCEPTION_H
