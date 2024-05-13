#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QLabel>

class CustomLabel : public QLabel
{
    Q_OBJECT

public:
    explicit CustomLabel(QWidget* parent = nullptr);
    void setHighlighted(bool highlighted);

signals:
    void cardClicked();

protected:
    void mousePressEvent(QMouseEvent* event) override;
private:
    bool highlighted;
};

#endif // CUSTOMLABEL_H
