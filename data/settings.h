#pragma once 

#include "../common.h"

class CSettings
{
public:
    CSettings();
    ~CSettings();

private:
    QSettings *registry = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"glad2see","g2s");
    
};