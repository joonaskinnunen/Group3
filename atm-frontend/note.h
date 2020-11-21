#ifndef NOTE_H
#define NOTE_H

#include <QLabel>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>



class Note
{
public:
    Note(QLabel *lbl, int count, QLabel *copy);
    int getCount() const;
    void setCount(int value);
    void setAnimation();
    QLabel *getLbl() const;
    void setLbl(QLabel *value);

    QPropertyAnimation *getAnimation() const;

    QLabel *getCopy() const;
    void setCopy(QLabel *value);

    QPropertyAnimation *getLoopAnim() const;
    void setLoopAnim();

private:
    int count;
    QLabel *lbl;
    QLabel *copy;
    QPropertyAnimation *anim;
    QPropertyAnimation *loopAnim;
};

#endif // NOTE_H
