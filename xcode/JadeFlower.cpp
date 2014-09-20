#include <vector>

#include <boost/bind.hpp>
#include <boost/coroutine/coroutine.hpp>

#include "cinder/app/AppBasic.h"
#include "cinder/Path2d.h"
#include "cinder/cairo/Cairo.h"
#include "cinder/ip/Fill.h"
#include "cinder/Rand.h"
#include "cinder/Utilities.h"
//#include "Resources.h"
#include "cinder/Font.h"
#include "cinder/params/Params.h"

#include "Constants.h"
#include "Flower.h"
#include "Petal.h"
#include "Grid.h"

using namespace ci;
using namespace ci::app;
using std::vector;

// The coroutine type.
typedef boost::coroutines::coroutine<int()> coro;

class JadeFlower : public AppBasic {
public:
	void prepareSettings( Settings* );
    void setup();
    void setupGUI();
	void mouseDown( MouseEvent event );
	void mouseMove( MouseEvent event );
	void keyDown( KeyEvent event );
	void renderBackground( cairo::Context &ctx );
	void renderScene( cairo::Context &ctx );
    void renderGrid( cairo::Context &ctx );
	void draw();
	void update();
	void forceFocus();

//	mowa::sgui::SimpleGUI*	_gui;
//    ciUICanvas*				_gui;
	float					mObjSize;

    Grid*               	_grid;
	vector<Vec2f>       endPoints;
	vector<Petal>		m_petals;
};

void JadeFlower::prepareSettings( Settings *settings ) {
	settings->setAlwaysOnTop( true );
	settings->setFrameRate( 60.0f );
}
void JadeFlower::setup(){
    ci::Vec2i spacing = ci::Vec2i(44, 26);
    setWindowSize( spacing.x*24, spacing.y*25 );
    _grid = new Grid( getWindowSize(), spacing );

    Constants::init();
    setupGUI();
}

void JadeFlower::setupGUI() {
//	std::cout << getResourcePath() << std::endl;//getResourcePath
//	std::string fontPath = "/pf_tempesta_seven.ttf";
//	std::cout << fontPath << std::endl;//getResourcePath

//	DataSourceRef fontResource = loadResource( fontPath );
//	ci::Font font = ci::Font( fontResource, 8);

//	mObjSize = 4;
//	mParams = params::InterfaceGl::create( getWindow(), "App parameters", toPixels( Vec2i( 200, 400 ) ) );
//	mParams->addParam( "Cube Size", &mObjSize, "min=0.1 max=20.5 step=0.5 keyIncr=z keyDecr=Z" );

//	mParams->addParam("c1 lerp", &Constants::Petal::C1_LERP_FACTOR, "min=0.0 max=1.0");
//	mParams->addParam("c2 lerp", &Constants::Petal::C2_LERP_FACTOR, "min=0.0 max=1.0");
//	mParams->addParam("c1 radius", &Constants::Petal::C1_RADIUS_SCALE, "min=0.0 max=1.0");
//	mParams->addParam("c1 radius", &Constants::Petal::C2_RADIUS_SCALE, "min=0.0 max=1.0");
}

void JadeFlower::forceFocus(){
	// This is a work hacky work around, to force our application to be above other windows when launched
	static bool hasBecomeFirstResponder = false;
	if( !hasBecomeFirstResponder && getElapsedSeconds() > 2 ) { // After 2 seconds, resume normal behavior
		hasBecomeFirstResponder = true;
		getWindow()->setAlwaysOnTop( false );
	}
}

void JadeFlower::keyDown( KeyEvent event )
{
	if( event.getCode() == KeyEvent::KEY_f ) {
		setFullScreen( ! isFullScreen() );
	}
	else if( event.getChar() == 'x' ) {
//		m_petals.clear();
	}
	else if( event.getChar() == 's' ) {
//		cairo::Context ctx( cairo::SurfaceSvg( getHomeDirectory() / "CairoBasicShot.svg", getWindowWidth(), getWindowHeight() ) );
//		renderScene( ctx );
	}
	else if( event.getChar() == 'e' ) {
//		cairo::Context ctx( cairo::SurfaceEps( getHomeDirectory() / "CairoBasicShot.eps", getWindowWidth(), getWindowHeight() ) );
//		renderScene( ctx );
	}
	else if( event.getChar() == 'p' ) {
//		cairo::Context ctx( cairo::SurfacePs( getHomeDirectory() / "CairoBasicShot.ps", getWindowWidth(), getWindowHeight() ) );
//		renderScene( ctx );
	}
	else if( event.getChar() == 'd' ) {
//		cairo::Context ctx( cairo::SurfacePdf( getHomeDirectory() / "CairoBasicShot.pdf", getWindowWidth(), getWindowHeight() ) );
//		renderScene( ctx );
	}
    else if( event.getChar() == 'c' ) {
    	m_petals.clear();
    }
    else if( event.getChar() == 'g' ) {
//		_gui->setEnabled( !_gui->isEnabled() );
    }
}

void JadeFlower::mouseMove( MouseEvent event ) {
    float p1 = (float)event.getX() / (float)getWindowWidth();
    float p2 = (float)event.getY() / (float)getWindowHeight();
    
    if( event.isControlDown() ) {
        Constants::Petal::C1_LERP_FACTOR = p1;
        Constants::Petal::C2_LERP_FACTOR = p2;
    } else if( event.isAltDown() ) {
        Constants::Petal::C1_RADIUS_SCALE = p1;
        Constants::Petal::C2_RADIUS_SCALE = p2;
    }
}

void JadeFlower::mouseDown( MouseEvent event ) {

	static GridPoint* currentStartPoint = NULL;
	static ci::ColorA flowerColor;
	static float hue = ci::Rand::randFloat();
    static DIRECTION newDirection = DIRECTION::NORTH_WEST;

    
	if( currentStartPoint == NULL ) {
		currentStartPoint = _grid->getCenterGridPoint();
		flowerColor = ci::ColorA( ci::CM_HSV, hue, 1, 1, 0.60f );
	} else {
		GridPoint* lastPoint = currentStartPoint;
		int i = 0;
		currentStartPoint = NULL;
		while(currentStartPoint == NULL) {
            newDirection = (DIRECTION)((newDirection+1) % ((int)DIRECTION::SOUTH_WEST+1));
            GridPoint* possiblePoint = _grid->getGridPointNeighbor(lastPoint, newDirection );
            currentStartPoint = possiblePoint;
			i++;
		}

		hue = ci::math<float>::fmod(hue + ci::randFloat(0.01f, 0.05f), 1.0f );
		flowerColor = ci::ColorA( ci::CM_HSV, hue, 1, 1, 0.60f );
	}
  
    
//    currentStartPoint->addStartPetal( newDirection, <#Petal *petal#>)
    
//    GridPoint* endPoint = _grid->getGridPointNeighbor(currentPoint, (DIRECTION)i );
//    if( endPoint == NULL ) continue;
//    
//    Petal aPetal = Petal( currentPoint, endPoint, (DIRECTION)i, flowerColor );
//    m_petals.push_back( aPetal );


//    // Draw all the petals around this point
//	for( int i = 0; i < 1; i++ ) {
//		GridPoint* endPoint = _grid->getGridPointNeighbor(currentPoint, (DIRECTION)i );
//        if( endPoint == NULL ) continue;
//        
//        Petal aPetal = Petal( currentPoint, endPoint, (DIRECTION)i, flowerColor );
//        m_petals.push_back( aPetal );
//	}
}

void JadeFlower::renderBackground( cairo::Context &ctx ) {
    // clear the context with our radial gradient
	cairo::GradientRadial radialGrad( getWindowCenter(), 0, getWindowCenter(), getWindowWidth() );
	radialGrad.addColorStop( 0, Color( 1, 1, 1 ) );
	radialGrad.addColorStop( 1, Color( 0.6, 0.6, 0.6 ) );
	ctx.setSource( radialGrad );
	ctx.paint();
}


void JadeFlower::renderGrid( cairo::Context &ctx ) {
    int columnCount = _grid->getColumnCount();
    int rowCount = _grid->getRowCount();

    ctx.newPath();
    ctx.setSource( Color( 0.8, 0.8, 0.8 ) );
    for( int x = 0; x < columnCount; x++ ) {
        for( int y = 0; y < rowCount; y++ ) {
            GridPoint* point = _grid->getGridPointAt(x, y);
            ctx.circle( point->pixelPosition.x, point->pixelPosition.y, 2);
        }
    }
    ctx.fill();
}


void JadeFlower::renderScene( cairo::Context &ctx ) {
	for( vector<Petal>::iterator flIt = m_petals.begin(); flIt != m_petals.end(); ++flIt ) {
		flIt->draw( ctx );
	}
}

void JadeFlower::update(){
    for( vector<Petal>::iterator petal = m_petals.begin(); petal != m_petals.end(); ) {
        if( petal->getColor().a < 0.02f ) {
            petal->destroy();
            petal = m_petals.erase( petal );
        } else {
            petal++;
        }
	}
    
	forceFocus();
}
void JadeFlower::draw() {
//	gl::clear( ci::ColorA::white())
	// render the scene straight to the window
	cairo::Context ctx( cairo::createWindowSurface() );
	renderBackground( ctx );
	renderGrid( ctx );
	renderScene( ctx );

	// Draw the interface
//	if( getElapsedSeconds() > 2 ) // After 2 seconds, resume normal behavior
//		mParams->draw();
}

CINDER_APP_BASIC( JadeFlower, Renderer2d )
