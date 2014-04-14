#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CircleMandalaApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void CircleMandalaApp::setup()
{
}

void CircleMandalaApp::mouseDown( MouseEvent event )
{
}

void CircleMandalaApp::update()
{
}

void CircleMandalaApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( CircleMandalaApp, RendererGl )
