#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType {Asteroid,Cycloid,HuygensCycloid,HypoCycloid,Line};

    void setBackgroundColor (QColor color) {mBackgroundColor=color;}
    QColor backgroundColor () const {return mBackgroundColor;}

    void setShapeColor (QColor color){mShapeColor=color;}
    QColor shapeColor() const {return mShapeColor;}

    void setShape (ShapeType shape) {mShape=shape; on_shape_changed();}
    ShapeType shape () const {return mShape;}

    void setScale (float scale) {mScale=scale; repaint();}
    float scale() const {return mScale;}

    void setIL (float intervalLength) {mIntervalLength=intervalLength; repaint();}
    float intervalLength() const {return mIntervalLength;}

    void setStepCount(int count) {mStepCount=count;repaint();}
    int stepCount() const {return mStepCount;}

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:

private:
    void on_shape_changed();
    QPointF compute(float t);
    QPointF compute_asteroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_hyugens(float t);
    QPointF compute_hypo(float t);
    QPointF compute_line(float t);

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int mStepCount;
};

#endif // RENDERAREA_H
