#include "tablemodel.h"

#include "qcolor.h"

TableModel::TableModel(QList<QList<QString> > v, QList<QString> Hh, QList<QString> Vh, QObject *parent)
    : QAbstractTableModel(parent), values(v), horizontalHeader(Hh), verticalHeader(Vh){}

int TableModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return values.size();
}

int TableModel::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return values[0].size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const{
    if (role == Qt::DisplayRole) {
        return values[index.row()].at(index.column());
    } else if (role == Qt::EditRole) {
        return values[index.row()].at(index.column());
    } else if (role == Qt::BackgroundRole) {
        return QColor(Qt::white);
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        return horizontalHeader.at(section);
    }
    if (orientation == Qt::Vertical && role == Qt::DisplayRole) {
        return verticalHeader.at(section);
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}
