#include <QtWidgets/QWidget>

class RegWindow : public QWidget
{
public:
    RegWindow();
    ~RegWindow();
private:
    QWidget widget;
    Qt::WindowFlags flags = Qt::Window | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint;
    int weight = 350;
    int height = 200;
    const QString title = "glad2see - join with us";
};