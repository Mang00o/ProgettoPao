#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class ListModel : public QAbstractListModel{
private:
    QStringList dataList;
public:
    ListModel(const QStringList &data, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // LISTMODEL_H
