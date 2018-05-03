#ifndef QCONVERT_H
#define QCONVERT_H

#include <QMainWindow>

namespace Ui {
class QConvert;
}

class QConvert : public QMainWindow
{
    Q_OBJECT

public:
    explicit QConvert(QWidget *parent = 0);
    ~QConvert();

private:
    Ui::QConvert *ui;
};

#endif // QCONVERT_H
