#ifndef FRMMODIFIERS_H
#define FRMMODIFIERS_H

#include "client/vues/blofeld/parts/frmmodifier.h"


class frmModifiers:
        public ctrlComposite
{
public:
    frmModifiers(const BlofeldReplica *synth ,Instrument *instru, QWidget *parent);
};

#endif // FRMMODIFIERS_H
