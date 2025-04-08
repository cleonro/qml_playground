#ifndef CBMODEL_H
#define CBMODEL_H

#include <QAbstractListModel>

class CBModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CBModel(QObject *parent = nullptr);

    // Header:
    // QVariant headerData(int section,
    //                     Qt::Orientation orientation,
    //                     int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setItems(const QStringList &items);

private:
    QStringList m_items;

};

#endif // CBMODEL_H
