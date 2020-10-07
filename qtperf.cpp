#include "qtperf.hpp"

#include <QApplication>
#include <QPainter>
#include <QMouseEvent>

int const gGridSize = 100;

TestPerf::TestPerf(QWidget* parent, Qt::WindowFlags flags)
    : QWidget(parent, flags),
      mLastPosition(0, 0),
      mShowGrid(false)
{
    setMouseTracking(true);
}

void TestPerf::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(Qt::black);

    for (int i = mLastPosition.x() % gGridSize; i < painter.device()->width(); i += gGridSize) {
        painter.drawLine(i, 0, i, size().height());
    }
    for (int i = mLastPosition.y() % gGridSize; i < painter.device()->height(); i += gGridSize) {
        painter.drawLine(0, i, size().width(), i);
    }
    
    painter.fillRect(mLastPosition.x()-5, mLastPosition.y()-5, 10, 10, Qt::black);
}

void TestPerf::mouseMoveEvent(QMouseEvent* event)
{
    mLastPosition = event->pos();
    update();
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_CompressHighFrequencyEvents);

    TestPerf mainWin;
    mainWin.show();
    
    return app.exec();
}
