#include "tstmodel.h"

#include <QDebug>

TstModel::TstModel(QObject *parent)
    : QObject{parent}
{
    m_choiceList << new ChoiceItem("Choice1", "A...v1", "Bv1", true, this)
        << new ChoiceItem("Test..........2", "Av2", "B....v2", true, this)
        << new ChoiceItem("Selection.....3", "A...v3", "Bv3", true, this);
}

TstModel::~TstModel()
{
    qDebug() << Q_FUNC_INFO<< "  option1:"
             << m_option1 << ", number: " << m_number
             << ", selectedIndex: " << m_selectedIndex;
}

QString TstModel::id_label() const
{
    qDebug() << Q_FUNC_INFO << "  id_label:" << m_id_label;
    return m_id_label;
}

void TstModel::setId_label(const QString &newId_label)
{
    if (m_id_label == newId_label)
        return;
    m_id_label = newId_label;
    emit id_labelChanged();
    qDebug() << Q_FUNC_INFO << "  id_label:" << m_id_label;
}

bool TstModel::option1() const
{
    qDebug() << Q_FUNC_INFO << "  option1:" << m_option1;
    return m_option1;
}

void TstModel::setOption1(bool newOption1)
{
    if (m_option1 == newOption1)
        return;
    m_option1 = newOption1;
    emit option1Changed();

    qDebug() << Q_FUNC_INFO << "  option1:" << m_option1;
}

int TstModel::number() const
{
    return m_number;
}

void TstModel::setNumber(int newNumber)
{
    if (m_number == newNumber)
        return;
    m_number = newNumber;
    emit numberChanged();
}

QStringList TstModel::selections()
{
    return m_selections;
}

void TstModel::setSelections(const QStringList &newSelections)
{
    qDebug() << Q_FUNC_INFO << "  newSelections:" << newSelections;

    if (m_selections == newSelections)
        return;
    m_selections = newSelections;
    emit selectionsChanged();
}

int TstModel::selectedIndex() const
{
    qDebug() << Q_FUNC_INFO << "  selectedIndex:" << m_selectedIndex;
    return m_selectedIndex;
}

void TstModel::setSelectedIndex(int newSelectedIndex)
{
    if (m_selectedIndex == newSelectedIndex)
        return;
    m_selectedIndex = newSelectedIndex;
    emit selectedIndexChanged();
    qDebug() << Q_FUNC_INFO << "  selectedIndex:" << m_selectedIndex;
}

QQmlListProperty<ChoiceItem> TstModel::choiceList()
{
    return QQmlListProperty<ChoiceItem>(this, &m_choiceList);
}

void TstModel::setChoiceList(const QList<ChoiceItem *> &newChoiceList)
{
    if (m_choiceList == newChoiceList)
        return;
    m_choiceList = newChoiceList;
    emit choiceListChanged();
}
