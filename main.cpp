#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QWidget widget;
    widget.resize(640, 480);
    widget.setWindowTitle("Hello World!!!");
    widget.show();

    return app.exec();
}