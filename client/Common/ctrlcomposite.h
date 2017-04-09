#ifndef ctrlcomposite_H
#define ctrlcomposite_H

#include "client/Common/ctrlBasics/CtrlsImport.h"
#include "ctrlcomponent.h"
#include "Messaging/dumpinstrument.h"
#include "Messaging/dumpmulti.h"



class ctrlComposite :
        public ctrlComponent
 {
protected:

    QVector<ctrlComponent *> _ctrls;
 public:
    ctrlComposite(QWidget * p,
                  QBoxLayout::Direction d);
    ~ctrlComposite();

    void addCtrl(ctrlComponent * c);
    void show();
    void hide();
    QVector<CtrlParamLeaf *> getLeafs();
    virtual void setLayout();

};

class ctrlSection :
        public ctrlComposite
 {
    QString _nom;
 public:
    ctrlSection(
                    QString nom,
                    QWidget * p,
                    QBoxLayout::Direction d )
        :ctrlComposite( p,d),_nom(nom){}
    void setLayout();

};


#endif // ctrlcomposite_H
