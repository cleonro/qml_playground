#include "choiceitem.h"

#include <QDebug>

ChoiceItem::ChoiceItem(QObject *parent)
: QObject{parent}
{}

ChoiceItem::ChoiceItem(const QString &label,
                       const QString &option1,
                       const QString &option2,
                       bool checked,
                       QObject *parent)
    : m_label(label)
    , m_option1(option1)
    , m_option2(option2)
    , m_checked(checked)
    , QObject{parent}
{}

QString ChoiceItem::label() const
{
    return m_label;
}

void ChoiceItem::setLabel(const QString &newLabel)
{
    if (m_label == newLabel)
        return;
    m_label = newLabel;
    emit labelChanged();
}

QString ChoiceItem::option1() const
{
    return m_option1;
}

void ChoiceItem::setOption1(const QString &newOption1)
{
    if (m_option1 == newOption1)
        return;
    m_option1 = newOption1;
    emit option1Changed();
}

QString ChoiceItem::option2() const
{
    return m_option2;
}

void ChoiceItem::setOption2(const QString &newOption2)
{
    if (m_option2 == newOption2)
        return;
    m_option2 = newOption2;
    emit option2Changed();
}

bool ChoiceItem::checked() const
{
    qDebug() << Q_FUNC_INFO << " checked: " << m_checked;
    return m_checked;
}

void ChoiceItem::setChecked(bool newChecked)
{
    if (m_checked == newChecked)
        return;
    m_checked = newChecked;
    emit checkedChanged();
    qDebug() << Q_FUNC_INFO << " checked: " << m_checked;
}
