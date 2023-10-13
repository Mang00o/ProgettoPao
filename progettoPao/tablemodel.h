#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel{
    Q_OBJECT
public:
    TableModel(QList<QList<QString>> v, QList<QString> horizHeader, QList<QString> vertHeader, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    private:
    QList<QList<QString>> values;
    QList<QString> horizontalHeader;
    QList<QString> verticalHeader;
};

#endif // TABLEMODEL_H
