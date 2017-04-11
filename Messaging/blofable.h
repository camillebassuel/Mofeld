#ifndef MESSAGEBLOFELD_H
#define MESSAGEBLOFELD_H

#include "sysexable.h"

class Blofable:public Sysexable
{
public:
    Blofable(const int s,const int type);
    QString getStructureName();

    QString getInstrument(int adresse);
    int getDevice();
    void setDevice(const int d);

    std::vector<uchar> * getMessage(int macid);

protected:


private:
    void setManufacturer();
    void setDeviceModel();
    void setDevice();
    void setType(const int t);

    virtual void setAdressContent()=0;
    virtual void setDataContent()=0;
    virtual void setChecksum()=0;
};



#endif // MESSAGEBLOFELD_H
