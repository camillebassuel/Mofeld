#include "ctrlcomponent.h"


void ctrlComponent::CompactLayout(QBoxLayout * layout)
{
    QSpacerItem* spacer = new QSpacerItem(0,0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    if(         _direction == QBoxLayout::TopToBottom
            ||  _direction == QBoxLayout::BottomToTop
                )
    {
        spacer->setAlignment(Qt::AlignTop);
        layout->addSpacerItem(spacer);
    }
//    else if(
//                _direction == QBoxLayout::LeftToRight
//            ||  _direction == QBoxLayout::RightToLeft
//            )
//    {
//        spacer->setAlignment(Qt::AlignLeft);
//        layout->addSpacerItem(spacer);
//    }
    layout->setSpacing(1);
    layout->setContentsMargins(0,0,0,0);
}

