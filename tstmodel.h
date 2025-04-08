#ifndef TSTMODEL_H
#define TSTMODEL_H

#include "choiceitem.h"

#include <QObject>
#include <QString>
#include <QVariantList>
#include <QQmlListProperty>

class TstModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id_label READ id_label WRITE setId_label NOTIFY id_labelChanged FINAL)
    Q_PROPERTY(bool option1 READ option1 WRITE setOption1 NOTIFY option1Changed)
    Q_PROPERTY(int number READ number WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QStringList selections READ selections NOTIFY selectionsChanged FINAL)
    Q_PROPERTY(int selectedIndex READ selectedIndex WRITE setSelectedIndex NOTIFY selectedIndexChanged FINAL)
    Q_PROPERTY(int selectedIndex READ selectedIndex WRITE setSelectedIndex NOTIFY selectedIndexChanged FINAL)
    Q_PROPERTY(QQmlListProperty<ChoiceItem> choiceList READ choiceList NOTIFY choiceListChanged FINAL)

public:
    explicit TstModel(QObject *parent = nullptr);
    ~TstModel();

    QString id_label() const;
    void setId_label(const QString &newId_label);

    bool option1() const;
    void setOption1(bool newOption1);

    int number() const;
    void setNumber(int newNumber);

    QStringList selections();
    void setSelections(const QStringList &newSelections);

    int selectedIndex() const;
    void setSelectedIndex(int newSelectedIndex);

    QQmlListProperty<ChoiceItem> choiceList();
    void setChoiceList(const QList<ChoiceItem *> &newChoiceList);

signals:

    void id_labelChanged();

    void option1Changed();

    void numberChanged();

    void selectionsChanged();

    void selectedIndexChanged();

    void choiceListChanged();

private:
    QString m_id_label;
    bool m_option1 = true;
    int m_number = 5;

    QStringList m_selections = {"Selection1", "Selection2", "Selection3"};
    int m_selectedIndex = 1;

    QList<ChoiceItem*> m_choiceList;

};

#endif // TSTMODEL_H
