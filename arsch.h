#ifndef ARSCH_H
#define ARSCH_H

#include <QWidget>

namespace Ui {
class Arsch;
}

class Arsch : public QWidget
{
    Q_OBJECT

public:
    explicit Arsch(QWidget *parent = 0);
    ~Arsch();

 signals:
    void GoBack();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Arsch *ui;
};

#endif // ARSCH_H
