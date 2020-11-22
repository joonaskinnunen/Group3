#include "note.h"

Note::Note(QLabel *lbl, int count, QLabel *copy)
{
    this->lbl = lbl;
    this->count = count;
    this->setAnimation();
    this->setCopy(copy);
    if(count > 1) this->setLoopAnim();
}

int Note::getCount() const
{
    return count;
}

void Note::setCount(int value)
{
    count = value;
}

void Note::setAnimation()
{
    anim = new QPropertyAnimation(this->lbl, "geometry");
    anim->setDuration(1500);
    anim->setStartValue(lbl->geometry());
    anim->setEndValue(QRect(260,520,190,90)); //full height 102
}

QLabel *Note::getLbl() const
{
    return lbl;
}

void Note::setLbl(QLabel *value)
{
    lbl = value;
}

QPropertyAnimation *Note::getAnimation() const
{
    return anim;
}

QLabel *Note::getCopy() const
{
    return copy;
}

void Note::setCopy(QLabel *value)
{
    copy = value;
}

QPropertyAnimation *Note::getLoopAnim() const
{
    return loopAnim;
}

void Note::setLoopAnim()
{
    copy->setPixmap(*lbl->pixmap());
    loopAnim = new QPropertyAnimation(copy, "geometry");
    loopAnim->setDuration(1500);
    loopAnim->setStartValue(copy->geometry());
    loopAnim->setEndValue(QRect(260,520,190,90)); //full height 102
    loopAnim->setLoopCount(count -1);
}
