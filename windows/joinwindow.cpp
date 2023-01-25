#include "joinwindow.h"
#include "../data/database.h"


#define         JOINWND_W_SIZE          400
#define         JOINWND_H_SIZE          200

void CJoinWindow::clicked_onJoin()
{
    QSqlQuery q;
    q.prepare("SELECT id FROM users WHERE name = :name");
    q.bindValue(":name", leUser->text());
    if(!q.exec())
    {
        qDebug() << "Can't execute the query";
    }
    else
    {
        if(!q.next()) QMessageBox::warning(this, "glad2see - failed authorization", "Please, contact to vk.com/reussssya if you already don't have an account\
                                                   Or try again..."); // if there no account in db do sth                    
    }

    q.clear();
    q.finish();

    q.prepare("SELECT giftcode FROM users WHERE name = :name");
    q.bindValue(":name", leUser->text());

    if(!q.exec()) qDebug() << "Can't execute the query";
    while(q.next())
    {
        QString receivedCode = q.value(0).toString();
        if(receivedCode == leCode->text())
        {
            QSettings registry(QSettings::NativeFormat,QSettings::UserScope,"glad2see","g2s");
            registry.setValue("bIsAuthed", 0);
            registry.setValue("user", leUser->text());
            QMessageBox::information(this, "glad2see - you are welcome", "Successfuly joined in your account\nEnjoy...");
            //this->setAttribute(Qt::WA_QuitOnClose, false);


            emit exec_mainWindow();
            this->close();
        }
        else if(receivedCode != leCode->text())
        {
            QMessageBox::warning(this, "glad2see - failed authorization", "Please, contact to vk.com/reussssya if you forgot the password\
                                                   Or try again..."); // if there no account in db do sth
        }
    }
    
}


void CJoinWindow::applyCustomDesign()
{
    QPixmap temp_pixmap;
    QByteArray byteRegIcon = "iVBORw0KGgoAAAANSUhEUgAAAEAAAABACAYAAACqaXHeAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAOuSURBVHgB7Zs9T1NRGMefqgSDCe3kJC0z4WXQEIIpAwkJBDo41aGJLsIA0QFwaBcTLUNxMjCAiyQlyuTQRjpgTGiUhakgDDhA+QKUL6D93+TcnluKpT3PISTn/BJjL4V7e/7P63kO+Nra7v8lg7lFhmMFIMOxApDhWAHIcKwAZDhWADIcKwAZjhWADOcOXROBQDuNj4/R0NAg9fZ2UygUJL+/3XmvVDqnk5MiFQq/KZ//SdnsJp2dndN14NM9EAmFOmh6epJisafugq9COr1BCwuLZWFOSSfaBIDF4/HX5cW/IBWSycWyEO9JF1oEgNVzua8UDHZ4vg63LhT2KJPJUbF4Wnb9kvteT0+3Ex6RyNiF++F7R0efaPEGdgEQ3xsbnzyLx8KXl1fK/1adeP8f+LlweJASiXlHSAFEiEafOXmCE1YBalkei4Yb11t4NbhHIjHn5A6BDk9gFeDwcNezeI74hSfE43PuNUQYGBhuWNDLuN3Scu8NMYAPOjFRiV+u5JXP/yKfz+eEBfD7/dTaepe2tn4QByweANc/ONh1r9PpLzQ19Yo4SaXeOuVU0NX1iCUUWDrBeHzefY0PlUzyly3cU3Z7WQwVlAWAS8ZiUfcaro845QYlEwlVgGc20lhdhrIAkcio5xoxq4ulpUoZhfByzmkWZQHC4cfu60zmmxbrC+AFhcK+e43GSRVlAdD4CHRaX5DJbLqv0T2qoiyA3K1xd2m1kDN/Z2cHqcKQBNUTUSPI+wfkAVXsRIgUkWszh0Uae3aJVFEWQI7JUOgB6UZOusfHN6ATxP5ewFGX6yGXvr29fVJFWYDt7Urp6+vr1poUUXFkkeVnN4uyANlsztOdcfXotRA7wsqzN0kVhiRYcnZ/gpmZSS1eAOtjyy3AMzlmAixlED26AF4g7w65wD29wxaeHSfLQASWCAT81N//0LkW/3O1xrC8HFrYcSL0OGAbicHyOzvfPa2xjpEYyi6GIVywdYLIBdUDS3z4lZUPHlGuCs4VUql3FxaPZ3DCNhMECAW4/cjIsBMSAI0LZv0QCO/XS1xY+OzsS1pbW/VkfSw+Gn1OR0d/iBMtByNIVhiP17I8trMQSd7Xo2rgrBBCQbDqKiIsr2PWoPVssDp+m6HZc4Wrov1wtNYBRz1wkrS+/rlcXj9qnTAB33X9ujzcGm2sOB4PBoNOvAMsuFgsOmGB9hYdni6LV+Ozfy9gOFYAMhwrABmOFYAMxwpAhmMFIMOxApDhWAHIcP4BqrKETZYLXSoAAAAASUVORK5CYII=";
    temp_pixmap.loadFromData(QByteArray::fromBase64(byteRegIcon));
    QIcon regIcon(temp_pixmap);
    this->setWindowIcon(regIcon);

    this->setFixedSize(JOINWND_W_SIZE, JOINWND_H_SIZE);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // background 
    QPixmap bkgnd("data/img/JoinWindow.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);

    this->setPalette(palette);

    // round window's corners

    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 5, 5, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

}


CJoinWindow::CJoinWindow(QWidget *parent) : QWidget(parent)
{
    applyCustomDesign();

    QPixmap pngIdentificator, pngCode, pngJoinWithUs;

    QByteArray bytePngIdentificator = "iVBORw0KGgoAAAANSUhEUgAAAJQAAAAQCAYAAADwHVYaAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAQ/SURBVHgB7VntcdswDIV7/V9lgjATNJnA6gRJJogygZMJ7E4QZwI7E9SZwMoEdSawOkGcCVg8i2ogmNSHZfvqu7w7nkQQoCAQBECJ6BOf2CF61lrD17mgzXq93j3TH/j+yiOTcVs5vic9WCGncc3yC+bHs42jPTFtVDNf7Pp31BxjnveR51oKWsq0W6YNGs517fR8ELQ7nuOZyvrGfBk4PSNHXnAD35T5s9ADWHbGl++KXLJJgKdSb9i5gX5jbi9aP7U+EvAB8Jb9AA5ly5g4+sTWY8ntXCnQRA7oO/6losc1851yG9p2GLq5JOaONrTN0OeWKNqN0nVaM8fSKntVrEOBN73Ath36XfSzm+sTkjPg/0LdYLjNbcBIW2LC80V0ZGCdscNvatgM5fYynrE4IBNZtcm2wQ70q5NbB6KvLYSQFhDmIndvHB19pIEfAbmE8tCo8Uph5RBR7ikMhNhU9GNuI9GH8Wai/4eaA++28NCh75lPwC3AQJHHQkfcG3cfOV79flWLfSnmgtw3KusrS4KEyvZ+tR9pTmJE+XueUG5vI/SDc/jWM6Pc1ifuKtN/vA4EtnnKO5Uz283QGzeR07DhkNp4PluTigSfRCjl9St09T7Ho+NQySHKvInxpRrXazC3Zbu8Veg0sfX20TyDGv2AiDbXR+s9VzL9NhFK45HKYRqFYurhu+IHvStaxoWcj1diwnIXdHhAXx2J6vTVKb90WGHZFc+Z0EcRrBGr/tTNWRwW1mmvgc266Del8uEEG+uZWqKLQ+m0EKqjxh5aSn7nkzBUDqmHgu/EN6VqfY24X/lOcvo0qHCp+i+Up+k7xZPSdpBrg82x8vBkqu9z/khE35g2N8JrF4faR+GcUR75CkdKKK/bjgmt9HWpRdZAC+eQGY8VNSuQUHVdeQhAl1FgbARH3aVDZQE+FMerhrzYyWM2JHZjHHjOvuHTN62RkQuPeigKRAEfrjRBRIGMPqJLl7SXUbno9sGofpuNge9xCASdUp4ufBcUflibUxZwy+03Hd6ZAHwEfWkpk1IeQQrANo+SwRW0xnWRFk/cvU535xQuH7ZNe5l4dsgxtWP7TuFwsrHjPffxtvkOdeZOIyhacRJMxFhWUyO0ggv5P+l4oP8YjNhGN85exhW8RowjCvrSXR0S2g66jp0I/c65/VL6LQJf9LERsC469f471baJUPOKsVHFGGoBHz2uigSe1PffAruddU2pnKanAXbs8mKzaGeaUfn7GYDCvFPaw2ZX+pkK/YBrqp5Pvy++Qd3gF0zXL+Uwzp3vn96OcEvHU5RD16yGp7BXwafTHf71PclGmwt/SfvTD0iq/jeq+SQQlaNtHSqjPIxeFMXYPuBe7JaOANCVG75fIaJkahiOlFJur/XmC6Q7X8TWpURCB9CvyXxUdnbDbdCjT+wFzmGKXyTvLU59B4HUb4tDUxB/AeL8wNawiB56AAAAAElFTkSuQmCC";
    QByteArray bytePngCode = "iVBORw0KGgoAAAANSUhEUgAAADcAAAAQCAYAAACycufIAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAIJSURBVHgB3VbRUQIxEF0cCsAKjBWIFYAVSAfYwWEFnBUIFYAVSAccFYAVXKwArCC+wMLEvSyXY/zRN/MmQ7Ivu3uXe4HoH6MlJ5xzTxiGYBfsgDtwA85brdabthF0PnbEWsPTFizAKbQbET/A8BrZynLOBbiCzgpdxnnqMAlFBly68yh9HFUbewK3Ndo8oqlDCY6EbuzSMA5FZaJoLZIZl468YXNHjC5uLpJoy5v0eK0U68MzD2UJPrJ25qowSk4fOwQz8D1ST0dpLuNckuZY4NopxfN6XxaizJeRI/sqYsZKc8MaXaY01yMFbX4i3WDOSuPA78IdjOaIHY93Yr8JVTGlnwbQB1+oHjHdNBI3QG23chI1z9t0cMQQNrIBKU5Zq/Vuh+ThlKEENNBpzjm/or+DXcN4akdEHUqH1BoZ4KpXh6UERHQaFqQ03sbr32EjGxTW9UbhvzORKDSLAusPGD/Efv5inkbmQlhKg9QVStwEtaxIQ8SBSnZCw6Pqpq56ec/ALmtzV0WPddItsyBfTGeUWlW3PBbYcemXeCm0A5eOWaBrcomPz7wIVbM3FH80MfhjZuk8LMedAK0/8znVowCfqTly5Ei5Oio4uSX/QfWFz6napG8+B+/lH1nW+uT3FP8u/NzIf6P8EFNguY7+pY3t69IW8FpvMFyDWyT4pAZgrcdXg4Z+Hd8lTmI8V7s7RwAAAABJRU5ErkJggg==";
    QByteArray byteJoinWithUs = "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";
    pngIdentificator.loadFromData(QByteArray::fromBase64(bytePngIdentificator));
    pngCode.loadFromData(QByteArray::fromBase64(bytePngCode));
    pngJoinWithUs.loadFromData(QByteArray::fromBase64(byteJoinWithUs));


    user->setPixmap(pngIdentificator);
    code->setPixmap(pngCode);
    //code->setPixmap(QPixmap("data/img/CODE.png"));
    joinWithUs->setPixmap(pngJoinWithUs);
    
    leUser->setStyleSheet("font: 13pt 'Inter';"
                        "color: #0A0A16;"
                        "background-color: #D9D9D9;"
                        "selection-color: #0A0A16;"
                        "border-radius: 5px;");
    leUser->setFixedHeight(35);

    leCode->setStyleSheet("font: 13pt 'Inter';"
                        "color: #0A0A16;"
                        "background-color: #D9D9D9;"
                        "selection-color: #0A0A16;"
                        "border-radius: 5px;");
    leCode->setFixedHeight(35);



    enter->setStyleSheet("QPushButton { border-image:url(data/img/joinButtonFinal.png); }"
                        "QPushButton:pressed { border-image:url(data/img/joinButtonFinalPressed.png); }");

    quit->setStyleSheet("QPushButton { border-image:url(data/img/quitButtonFinal.png); }"
                        "QPushButton:pressed { border-image:url(data/img/quitButtonFinalPressed.png); }");


    joinWithUs->setGeometry(145,12,110,20);
    
    user->setGeometry(27,46, 148,23);
    code->setGeometry(117,98, 58,19);

    leUser->setGeometry(190,40,190,35);
    leCode->setGeometry(190,90,190,35);

    enter->setGeometry(325, 160, 65, 25);
    quit->setGeometry(15, 160, 65, 25);


    //connect(quit, &QPushButton::pressed, this, &CJoinWindow::pressed_quitButton);
    //connect(quit, &QPushButton::, this, &CJoinWindow::applyCustomDesign);
    connect(quit, &QPushButton::clicked, this, &CJoinWindow::close);
    connect(enter, &QPushButton::clicked, this, &CJoinWindow::clicked_onJoin);
}

CJoinWindow::~CJoinWindow()
{

}


