#include "dialog_keygen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    espira::widgets::dialog_keygen w;
    w.show();

    return a.exec();
}
