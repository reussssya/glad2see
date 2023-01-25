#include "mainwindow.h"

#define         MAINWND_W_SIZE          1600
#define         MAINWND_H_SIZE          900

bool CMainWindow::bSubscriptionCheck()
{

    time_t currentTime = time(0);
    QSqlQuery subquery;
    // need to make if else construct to prevent errors while logging
    subquery.prepare("SELECT subscripted FROM users WHERE name = :name");
    subquery.bindValue(":name", qs->value("user").toString());
    subquery.exec();
    subquery.first();

    time_t reg = subquery.value(0).toDateTime().toTime_t();

    subquery.clear();
    subquery.finish();

    
    subquery.prepare("SELECT subtime FROM users WHERE name = :name");
    subquery.bindValue(":name", qs->value("user").toString());
    subquery.exec();
    subquery.first();
    time_t expreg = subquery.value(0).toInt();
    

    

    bool bExpired = (currentTime > reg+expreg ? true : false);

    return bExpired;
}

void CMainWindow::applyCustomDesign()
{
    QPixmap temp_pixmap;
    QByteArray byteMainIcon = "iVBORw0KGgoAAAANSUhEUgAAAEAAAABACAYAAACqaXHeAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAPMSURBVHgB7Zo7SFtRGMe/9AGiYJzqIOrUwWeGimjFQAXBFDO0iwGVdtKpLpoMSVsKPiCxSwuCdqoQQUGQolgd2iFBBW0LxtfQSQWhWyI4OLX3f+VcYpqbmvjdWDjnB8Fz470n+f7f43znEFth4b3fJDG3SHKUACQ5SgCSHCUASY4SgCRHCUCSowQgyVECkOQoAUhy7tANUFJSTHV1tVRRUU6JREJ7ndLOzi7F46eUb/ImQGVlOfX0eKi7u0sfp+Po6JgikXUaGxunw8Njygc2q88E4e1gcEQzviur58LhubwIYakAra0PaW5umuz2YuM9hPnS0jJtb+/p4Q/sdjs5HDXa/S2XogMR4fW+1O5fIauwTAB4fGrqvXENT/b3D1A0up7xOaRIIOC9JASeQ0RYgSUCuN0dNDs7bVxPTHwgn+8VZQNE8PuHjOuOjif/FC8X2AWA51ZWFvQKD0ZHx7Vcfku5kCwC0qWqqkFfMTi5ffdu0RtiJBQa0XMfXMd4AI+XlNipsfEBFRQUUGlpqVYPPhMnrBEA7+/vf9PHyPnq6gbiAHOKmoA5OVcG1k7Q7/caY3ifCxRBAYokJ6wCOJ0XoQ8PzcyYV21RJ05OftLZ2S+tYH40bY4AUkHkPpopTtgEwFouCl80umZ6Hwzd2Piq1wnRH7jdLu29LxlFWFxcNp5P7iuuC5sA9fU1xjgW2zW9LxQaTmsABJycfGf6XCy2l/RZtcQFawQIMm1qOjtdpv9zOMwNi8cTxlhEGgeMAlwtLDOt48ki5jpHtrAJgL5dgA2QGZnSQ+R5OtAPCMQeggM2Aa6ao319A2k9iLTx+V6bPpc8ZyYRs4VNAHhFNCio6mYgUpqa2jRvX3R0MDwSWaPm5rZLUZRK8hL7X6YAEGs/clm0w+mAoR7PcyoqKqWysvvkcj3NaDx2lldZYnOBtRXGlzw4uGiFYRA2LxxgTiEA5swkVrawRgC+WDg8q4/xhYPBYbou2BEK4zE3p/GAfTuM8IfHxLLItR1G7uNMgFsA9u3w+fk5bW5+N3p2p7NF/5vtYQa21YODL4xrbIi2tn4QN+wCAHgJL7EaQITeXo++UiQvl+lA8VxdXaD29kfGezB+fv4TWYGlh6Joe9H7px504ugba7lob9HkYC/hdj/+6wDV43lmyVGYwPJjcRSwQGAo620sCh7OEbmPwFKx5eu3wkKI1KPvZFDoYDhOgLmLnRm2m/ixNMIcrS1WDIxhLFLCam+nw6Z+LS45SgCSHCUASY4SgCRHCUCSowQgyVECkOQoAUhylAAkOX8AF76I1dwBXp4AAAAASUVORK5CYII=+QKUL6D93+TcnluKpT3PISTn/BJjL4V7e/7P63kO+Nra7v8lg7lFhmMFIMOxApDhWAHIcKwAZDhWADIcKwAZjhWADOcOXROBQDuNj4/R0NAg9fZ2UygUJL+/3XmvVDqnk5MiFQq/KZ//SdnsJp2dndN14NM9EAmFOmh6epJisafugq9COr1BCwuLZWFOSSfaBIDF4/HX5cW/IBWSycWyEO9JF1oEgNVzua8UDHZ4vg63LhT2KJPJUbF4Wnb9kvteT0+3Ex6RyNiF++F7R0efaPEGdgEQ3xsbnzyLx8KXl1fK/1adeP8f+LlweJASiXlHSAFEiEafOXmCE1YBalkei4Yb11t4NbhHIjHn5A6BDk9gFeDwcNezeI74hSfE43PuNUQYGBhuWNDLuN3Scu8NMYAPOjFRiV+u5JXP/yKfz+eEBfD7/dTaepe2tn4QByweANc/ONh1r9PpLzQ19Yo4SaXeOuVU0NX1iCUUWDrBeHzefY0PlUzyly3cU3Z7WQwVlAWAS8ZiUfcaro845QYlEwlVgGc20lhdhrIAkcio5xoxq4ulpUoZhfByzmkWZQHC4cfu60zmmxbrC+AFhcK+e43GSRVlAdD4CHRaX5DJbLqv0T2qoiyA3K1xd2m1kDN/Z2cHqcKQBNUTUSPI+wfkAVXsRIgUkWszh0Uae3aJVFEWQI7JUOgB6UZOusfHN6ATxP5ewFGX6yGXvr29fVJFWYDt7Urp6+vr1poUUXFkkeVnN4uyANlsztOdcfXotRA7wsqzN0kVhiRYcnZ/gpmZSS1eAOtjyy3AMzlmAixlED26AF4g7w65wD29wxaeHSfLQASWCAT81N//0LkW/3O1xrC8HFrYcSL0OGAbicHyOzvfPa2xjpEYyi6GIVywdYLIBdUDS3z4lZUPHlGuCs4VUql3FxaPZ3DCNhMECAW4/cjIsBMSAI0LZv0QCO/XS1xY+OzsS1pbW/VkfSw+Gn1OR0d/iBMtByNIVhiP17I8trMQSd7Xo2rgrBBCQbDqKiIsr2PWoPVssDp+m6HZc4Wrov1wtNYBRz1wkrS+/rlcXj9qnTAB33X9ujzcGm2sOB4PBoNOvAMsuFgsOmGB9hYdni6LV+Ozfy9gOFYAMhwrABmOFYAMxwpAhmMFIMOxApDhWAHIcP4BqrKETZYLXSoAAAAASUVORK5CYII=";
    temp_pixmap.loadFromData(QByteArray::fromBase64(byteMainIcon));
    QIcon mainIcon(temp_pixmap);
    this->setWindowIcon(mainIcon);

    this->setWindowFlags(flags);
    this->setFixedSize(MAINWND_W_SIZE, MAINWND_H_SIZE);


    this->setParent(0);

    // background 
    QPixmap bkgnd("data/img/mainWindow.png");
    bkgnd = bkgnd.scaled(this->size());

    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);

    this->setPalette(palette);

    // round window's corners

    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 5, 5, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());
}

CMainWindow::CMainWindow(QMainWindow *parent) : QMainWindow(parent)
{
    applyCustomDesign();
    

    if(!qs->value("bIsAuthed").toBool())
    {
        this->close();
        jwnd = new CJoinWindow();
        jwnd->show();
        connect(jwnd, &CJoinWindow::exec_mainWindow, this, &CMainWindow::show);

    }
    else if(bSubscriptionCheck())
    {
        this->close();
        jwnd = new CJoinWindow();
        jwnd->show();
        connect(jwnd, &CJoinWindow::exec_mainWindow, this, &CMainWindow::show);
        QMessageBox::information(this, "Your subscription has expired", "Wanna use this beautiful app again? :3\nContact: vk.com/reussssya or t.me/reussssya");
    }
    else
    {
        this->show();
    }

    

}

CMainWindow::~CMainWindow()
{

}