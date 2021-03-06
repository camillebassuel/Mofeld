#ifndef PROPRIETEVUE_H
#define PROPRIETEVUE_H


#include "BlofeldMgr/propriete.h"
#include "client/Models/proprietemodel.h"
#include "client/vues/edition/easylist.h"
#include "QCheckBox"
#include "QComboBox"
#include "QListWidget"
#include "client/vues/edition/easylist.h"

class ProprieteVue
        :public EasyList
{
    Q_OBJECT

    ProprieteModel * _model;
public:
    ProprieteVue( ProprieteModel * m,QWidget *parent )
        :EasyList("PROPRIETE",m,parent), _model(m)
    {
        setupModel();
        setLayout(_layout);
    }
    void connectAll(QWidget * parent);


public slots:
    void ajouterPropriete();
    void effacerPropriete();
    void envoyerPropriete(QModelIndex index );
signals:
    void envoyerPropriete(const Propriete * a);

};


#endif // PROPRIETEVUE_H
