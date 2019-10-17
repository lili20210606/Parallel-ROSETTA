
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_Formatter__
#define __java_util_Formatter__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace text
    {
        class DateFormatSymbols;
    }
  }
}

class java::util::Formatter : public ::java::lang::Object
{

public:
  Formatter();
  Formatter(::java::util::Locale *);
  Formatter(::java::lang::Appendable *);
  Formatter(::java::lang::Appendable *, ::java::util::Locale *);
  Formatter(::java::io::File *);
  Formatter(::java::io::File *, ::java::lang::String *);
  Formatter(::java::io::File *, ::java::lang::String *, ::java::util::Locale *);
  Formatter(::java::io::OutputStream *);
  Formatter(::java::io::OutputStream *, ::java::lang::String *);
  Formatter(::java::io::OutputStream *, ::java::lang::String *, ::java::util::Locale *);
  Formatter(::java::io::PrintStream *);
  Formatter(::java::lang::String *);
  Formatter(::java::lang::String *, ::java::lang::String *);
  Formatter(::java::lang::String *, ::java::lang::String *, ::java::util::Locale *);
  void close();
  void flush();
private:
  ::java::lang::String * getName(jint);
  void checkFlags(jint, jint, jchar);
  void noPrecision(jint);
  void applyLocalization(::java::lang::StringBuilder *, jint, jint, jboolean);
  void genericFormat(::java::lang::String *, jint, jint, jint);
  void booleanFormat(::java::lang::Object *, jint, jint, jint, jchar);
  void hashCodeFormat(::java::lang::Object *, jint, jint, jint, jchar);
  void stringFormat(::java::lang::Object *, jint, jint, jint, jchar);
  void characterFormat(::java::lang::Object *, jint, jint, jint, jchar);
  void percentFormat(jint, jint, jint);
  void newLineFormat(jint, jint, jint);
  ::java::lang::StringBuilder * basicIntegralConversion(::java::lang::Object *, jint, jint, jint, jint, jchar);
  void hexOrOctalConversion(::java::lang::Object *, jint, jint, jint, jint, jchar);
  void decimalConversion(::java::lang::Object *, jint, jint, jint, jchar);
  void singleDateTimeConversion(::java::lang::StringBuilder *, ::java::util::Calendar *, jchar, ::java::text::DateFormatSymbols *);
  void dateTimeConversion(::java::lang::Object *, jint, jint, jint, jchar, jchar);
  void advance();
  jint parseInt();
  jint parseArgumentIndex();
  jint parseFlags();
  jint parseWidth();
  jint parsePrecision();
public:
  ::java::util::Formatter * format(::java::util::Locale *, ::java::lang::String *, JArray< ::java::lang::Object * > *);
  ::java::util::Formatter * format(::java::lang::String *, JArray< ::java::lang::Object * > *);
  ::java::io::IOException * ioException();
  ::java::util::Locale * locale();
  ::java::lang::Appendable * out();
  ::java::lang::String * toString();
private:
  ::java::lang::Appendable * __attribute__((aligned(__alignof__( ::java::lang::Object)))) out__;
  ::java::util::Locale * locale__;
  jboolean closed;
  ::java::io::IOException * ioException__;
  ::java::lang::String * format__;
  jint index;
  jint length;
  ::java::util::Locale * fmtLocale;
  static ::java::lang::String * FLAGS;
  static ::java::lang::String * lineSeparator;
public: // actually package-private
  static jboolean $assertionsDisabled;
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_Formatter__
