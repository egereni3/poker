#include "CustomLabel.h"

CustomLabel::CustomLabel(QWidget* parent) : QLabel(parent), highlighted(false)
{

}

void CustomLabel::mousePressEvent(QMouseEvent* event)
{
    emit cardClicked();
    QLabel::mousePressEvent(event);
}

void CustomLabel::setHighlighted(bool highlighted)
{
    this->highlighted = highlighted;

    // Set a border when highlighted
    if (highlighted)
    {
        QPalette palette;
        palette.setColor(QPalette::WindowText, Qt::red);
        setAutoFillBackground(true);
        setPalette(palette);
        setLineWidth(2);
        setFrameShape(QFrame::Box);
    }
    else
    {
        setAutoFillBackground(false);
        setFrameShape(QFrame::NoFrame);
    }
}
