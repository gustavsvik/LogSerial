#include "Arduino.h"

#include <LogSerial.h>


#ifdef LOGLIMITLEVEL
/* LOGLIMITLEVEL is defined (see LogSerial.h), i.e. Log class member functions will implement wrappers around Arduino 
   library hardware serial communication library (Serial) functions and default to passing on their first argument to 
   the appropriate Arduino Serial library function. Hardware serial port logging via an individual Log member function 
   will then be effective if either no second argument (a_log_level) is passed, or it is passed and has an integer 
   value greater than the default LOGLIMITLEVEL or whichever value of a_log_limit_level that the default is overridden 
   by in the constructor.*/

Log::Log(int a_baud_rate, int a_log_limit_level) : m_baud_rate(a_baud_rate), m_log_limit_level(a_log_limit_level)
{
  Serial.begin(this->m_baud_rate);
}

void Log::write(int a_logged_int, int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.print(a_logged_int);
}

void Log::write(const char* a_logged_string, int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.print(a_logged_string);
}

void Log::write(char a_logged_char, int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.print(a_logged_char);
}

void Log::write(String a_logged_string, int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.print(a_logged_string);
}

void Log::write_hex(int a_logged_int, int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.print(a_logged_int, HEX);
}

void Log::linefeed(int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.println();
}

void Log::writeln(int a_logged_int, int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.println(a_logged_int);
}

void Log::writeln(const char* a_logged_string, int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.println(a_logged_string);
}

void Log::writeln(char a_logged_char, int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.println(a_logged_char);
}

void Log::writeln(String a_logged_string, int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.println(a_logged_string);
}

void Log::writeln_hex(int a_logged_int, int a_log_level) 
{ 
  if (a_log_level >= this->m_log_limit_level) Serial.println(a_logged_int, HEX);
}

#else
/* LOGLIMITLEVEL is not defined, i.e. Log class members will compile to empty functions which will not perform any 
   (useful) operations irrespective of argument(s), i.e. hardware serial port logging will effectively be disabled on 
   a global level at compile time. */

Log::Log(...) {}
void Log::write(...) {}
void Log::write_hex(...) {}
void Log::linefeed(...) {}
void Log::writeln(...) {}
void Log::writeln_hex(...) {}

#endif
