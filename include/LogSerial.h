#ifndef _LOGSERIAL_h
#define _LOGSERIAL_h

#include <LogSerialSwitch.h>

namespace Bus::SerialBus::Hard
{
  class Log
  {
    public:
      #ifdef LOGLIMITLEVEL
      /* LOGLIMITLEVEL is defined, i.e. Log class member functions will implement wrappers around Arduino library 
         hardware serial communication library (Serial) functions and default to passing on their first argument to 
         the appropriate Arduino Serial library function. Hardware serial port logging via an individual Log member 
         function will then be effective if either no second argument (a_log_level) is passed, or it is passed and has 
         an integer value greater than the default LOGLIMITLEVEL or whichever value of a_log_limit_level that the 
         default is overridden by in the constructor (see implementation in LogSerial.cpp).*/
      Log(int a_baud_rate = 9600, int a_log_limit_level = LOGLIMITLEVEL);
      void write(int a_logged_int, int a_log_level = LOGLIMITLEVEL);
      void write(char a_logged_char, int a_log_level = LOGLIMITLEVEL);
      void write(const char* a_logged_string, int a_log_level = LOGLIMITLEVEL);
      void write(String a_logged_string, int a_log_level = LOGLIMITLEVEL);
      void write_hex(int a_logged_int, int a_log_level = LOGLIMITLEVEL);
      void linefeed(int a_log_level = LOGLIMITLEVEL);
      void writeln(int a_logged_int, int a_log_level = LOGLIMITLEVEL);
      void writeln(char a_logged_char, int a_log_level = LOGLIMITLEVEL);
      void writeln(const char* a_logged_string, int a_log_level = LOGLIMITLEVEL);
      void writeln(String a_logged_string, int a_log_level = LOGLIMITLEVEL);
      void writeln_hex(int a_logged_int, int a_log_level = LOGLIMITLEVEL);
      #else
      /* LOGLIMITLEVEL is not defined, i.e. Log class members will compile to empty functions which will not perform 
         any (useful) operations irrespective of argument(s), i.e. hardware serial port logging will effectively be 
         disabled on a global level at compile time (see implementation in LogSerial.cpp). */
      Log(...);
      void write(...);
      void write_hex(...);
      void linefeed(...);
      void writeln(...);
      void writeln_hex(...);
      #endif
    private:
      #ifdef LOGLIMITLEVEL
      int m_baud_rate;
      int m_log_limit_level = LOGLIMITLEVEL;
      #endif
  };
}

#endif
