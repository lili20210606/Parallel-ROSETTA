
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_font_autofit_Segment__
#define __gnu_java_awt_font_autofit_Segment__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace font
        {
          namespace autofit
          {
              class Edge;
              class Segment;
          }
          namespace opentype
          {
            namespace truetype
            {
                class Point;
            }
          }
        }
      }
    }
  }
}

class gnu::java::awt::font::autofit::Segment : public ::java::lang::Object
{

public: // actually package-private
  Segment();
public:
  virtual ::java::lang::String * toString();
public: // actually package-private
  static const jint FLAG_EDGE_NORMAL = 0;
  static const jint FLAG_EDGE_ROUND = 1;
  static const jint FLAG_EDGE_SERIF = 2;
  static const jint FLAG_EDGE_DONE = 4;
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) dir;
  jint flags;
  ::gnu::java::awt::font::autofit::Segment * link;
  ::gnu::java::awt::font::autofit::Segment * serif;
  jint numLinked;
  jint pos;
  ::gnu::java::awt::font::opentype::truetype::Point * first;
  ::gnu::java::awt::font::opentype::truetype::Point * last;
  ::gnu::java::awt::font::opentype::truetype::Point * contour;
  jint minPos;
  jint maxPos;
  jint score;
  jint len;
  ::gnu::java::awt::font::autofit::Segment * edgeNext;
  ::gnu::java::awt::font::autofit::Edge * edge;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_font_autofit_Segment__
