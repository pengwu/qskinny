#include "MainWindow.h"
#include "SkinFactory.h"

#include <QskShortcut.h>
#include <QskSetup.h>
#include <SkinnyShortcut.h>

#include <QGuiApplication>
#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    QGuiApplication app( argc, argv );

    SkinFactory skinFactory;
    Qsk::registerSkinFactory( "SampleSkinFactory", &skinFactory );

    /*
        When going over QPainter for the SVGs we prefer the raster paint
        engine, simply showing better results. Interestingly the OpenGL paint
        engine was even slower for the use case of non-complex SVGs.
        Looks like its tesselation is not much faster than "pixeling"
        those images directly.
     */
    qskSetup->setControlFlag( QskSetup::PreferRasterForTextures, true );

    // Starting with a simple skin  made for this example
    // CTRL-S allow to rotate through the registered skins and CTRL-T
    // changes the colors, when the DefaultSkin is active.

    qskSetup->setSkin( "DefaultSkin" );

    cout << "CTRL-S to change the skin." << endl;
    cout << "CTRL-T to change the color scheme, when the \"Default\" skin is active." << endl;

    QskShortcut::addShortcut( QKeySequence( Qt::CTRL + Qt::Key_T ),
        &skinFactory, SLOT(toggleScheme()), false );

    QskShortcut::addShortcut( QKeySequence( Qt::CTRL + Qt::Key_S ),
        &skinFactory, SLOT(rotateSkin()), false );

    // With CTRL-B you can rotate a couple of visual debug modes
    SkinnyShortcut::enable( SkinnyShortcut::DebugBackground |
        SkinnyShortcut::DebugStatistics | SkinnyShortcut::Quit );

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
