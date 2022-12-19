#include "../common.h"

class RegWindow : public QWidget
{
    Q_OBJECT

public:
    RegWindow(QWidget *parent = 0);
    ~RegWindow();

signals:
    void signalFromButton(int buttonID);

private slots:
    void checkUser();

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
    QVector<QString> data {
        "username",
        "code",
    };

    QLineEdit *leUser = new QLineEdit(this);
    QLineEdit *leCode = new QLineEdit(this);

    QPushButton *enter = new QPushButton(labels[2], this);
    QPushButton *quit = new QPushButton(labels[3], this);
    //exit->setGeometry(50, 40, 75, 30);
};

struct oneofus
{
    std::string user;
    std::string code;
};