#include <QtGui/QApplication>
#include "sfml_test2.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    sfml_test2 foo;
    foo.show();
    return app.exec();
}
