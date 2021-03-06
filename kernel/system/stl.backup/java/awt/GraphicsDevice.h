
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_GraphicsDevice__
#define __java_awt_GraphicsDevice__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class DisplayMode;
        class GraphicsConfigTemplate;
        class GraphicsConfiguration;
        class GraphicsDevice;
        class Rectangle;
        class Window;
    }
  }
}

class java::awt::GraphicsDevice : public ::java::lang::Object
{

public: // actually protected
  GraphicsDevice();
public:
  virtual jint getType() = 0;
  virtual ::java::lang::String * getIDstring() = 0;
  virtual JArray< ::java::awt::GraphicsConfiguration * > * getConfigurations() = 0;
  virtual ::java::awt::GraphicsConfiguration * getDefaultConfiguration() = 0;
  virtual ::java::awt::GraphicsConfiguration * getBestConfiguration(::java::awt::GraphicsConfigTemplate *);
  virtual jboolean isFullScreenSupported();
  virtual void setFullScreenWindow(::java::awt::Window *);
  virtual ::java::awt::Window * getFullScreenWindow();
  virtual jboolean isDisplayChangeSupported();
  virtual void setDisplayMode(::java::awt::DisplayMode *);
  virtual ::java::awt::DisplayMode * getDisplayMode();
  virtual JArray< ::java::awt::DisplayMode * > * getDisplayModes();
  virtual jint getAvailableAcceleratedMemory();
  static const jint TYPE_RASTER_SCREEN = 0;
  static const jint TYPE_PRINTER = 1;
  static const jint TYPE_IMAGE_BUFFER = 2;
private:
  ::java::awt::Window * __attribute__((aligned(__alignof__( ::java::lang::Object)))) full_screen;
  ::java::awt::Rectangle * fullScreenOldBounds;
  ::java::awt::DisplayMode * mode;
public:
  static ::java::lang::Class class$;
};

#endif // __java_awt_GraphicsDevice__
