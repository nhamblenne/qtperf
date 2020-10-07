#ifndef QTPERF_HPP
#define QTPERF_HPP

#include <QOpenGLWidget>

class TestPerf: public QWidget
{
    Q_OBJECT
public:
    TestPerf(QWidget* parent=0, Qt::WindowFlags flags=0);

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    
private:
    QPoint mLastPosition;
    bool mShowGrid;
};

#endif
