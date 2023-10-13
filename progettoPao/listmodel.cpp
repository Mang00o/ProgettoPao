#include "listmodel.h"

ListModel::ListModel(const QStringList &data, QObject *parent)
    : QAbstractListModel(parent), dataList(data) {}

int ListModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return dataList.size();
}

QVariant ListModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return dataList.at(index.row());

    return QVariant();
}
