#include "cbmodel.h"

CBModel::CBModel(QObject *parent)
    : QAbstractListModel(parent)
{}

// QVariant CBModel::headerData(int section, Qt::Orientation orientation, int role) const
// {
//     // FIXME: Implement me!
// }

int CBModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    // if (parent.isValid())
    //     return 0;

    // FIXME: Implement me!
    Q_UNUSED(parent);
    return m_items.count();
}

QVariant CBModel::data(const QModelIndex &index, int role) const
{
    // if (!index.isValid())
    //     return QVariant();

    // FIXME: Implement me!
    // return QVariant();

    if (index.row() < 0 || index.row() >= m_items.count())
        return QVariant();

    if (role == Qt::DisplayRole) {
        return m_items.at(index.row());
    }
    return QVariant();
}

void CBModel::setItems(const QStringList &items)
{
    beginResetModel();
    m_items = items;
    endResetModel();
}
