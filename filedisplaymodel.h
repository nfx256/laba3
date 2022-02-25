#ifndef FILEDISPLAYMODEL_H
#define FILEDISPLAYMODEL_H
#include "Data.h"

#include <QAbstractItemModel>

class FileDisplayModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum class ColumnName {
        NAME = 0,
        SIZE,
        PERCENT
    };
    FileDisplayModel() = default;
    explicit FileDisplayModel(const QList<Data>& data, QObject *parent = nullptr);
    void setDataToModel(const QList<Data>& data);
    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
private:
    QList<Data> model_data;
};

#endif // FILEDISPLAYMODEL_H
