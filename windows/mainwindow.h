#include "../common.h"
#include <QMainWindow>

class mainWindow : public QMainWindow
{
public:
    mainWindow(QMainWindow* parent = 0);
    ~mainWindow();
private:
    QSize wndsize;
    Qt::WindowFlags flags = Qt::Window | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint;
    const QString title = "glad2see - private programkit";
};