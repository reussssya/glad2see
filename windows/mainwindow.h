#include <QWindow>
#include "../common.h"


class mainWindow : public QWindow
{
public:
    mainWindow();
    ~mainWindow();
private:
    QWindow window;
    QSize wndsize;
    Qt::WindowFlags flags = Qt::Window | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint;
    const QString title = "glad2see - private programkit";
};