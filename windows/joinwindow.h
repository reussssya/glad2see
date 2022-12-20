#include "../common.h"

class CJoinWindow : public QWidget
{
    Q_OBJECT

public:
    CJoinWindow(QWidget *parent = 0);
    ~CJoinWindow();


private slots:
    void clicked_onJoin();

private:
    Qt::WindowFlags flags = Qt::Window | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowMinimizeButtonHint;

    int weight = 275;
    int height = 100;

    QVector<QString> labels {
        "glad2see - join with us",
        "Enter your code:",
        "Join",
        "Quit",
    };

    QLineEdit *leUser = new QLineEdit(this);
    QLineEdit *leCode = new QLineEdit(this);

    QPushButton *enter = new QPushButton(labels[2], this);
    QPushButton *quit = new QPushButton(labels[3], this);
};