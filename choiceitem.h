#ifndef CHOICEITEM_H
#define CHOICEITEM_H

#include <QObject>

class ChoiceItem : public QObject
{
    Q_OBJECT
public:
    explicit ChoiceItem(QObject *parent = nullptr);
    ChoiceItem(const QString& label, const QString& option1, const QString& option2, bool checked, QObject *parent = nullptr);

    QString label() const;
    void setLabel(const QString &newLabel);

    QString option1() const;
    void setOption1(const QString &newOption1);

    QString option2() const;
    void setOption2(const QString &newOption2);

    bool checked() const;
    void setChecked(bool newChecked);

signals:

    void labelChanged();

    void option1Changed();

    void option2Changed();

    void checkedChanged();

private:
    QString m_label;
    QString m_option1;
    QString m_option2;
    bool m_checked = true;
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged FINAL)
    Q_PROPERTY(QString option1 READ option1 WRITE setOption1 NOTIFY option1Changed FINAL)
    Q_PROPERTY(QString option2 READ option2 WRITE setOption2 NOTIFY option2Changed FINAL)
    Q_PROPERTY(bool checked READ checked WRITE setChecked NOTIFY checkedChanged FINAL)
};

#endif // CHOICEITEM_H
