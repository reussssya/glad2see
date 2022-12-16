#include "regwindow.h"
#include "../common.h"


RegWindow::RegWindow()
{
    
    widget.setWindowFlags(flags);
    widget.setFixedSize(weight, height);
    widget.setWindowTitle(title);
    widget.show();
}
RegWindow::~RegWindow()
{

}