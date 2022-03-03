#ifndef FILEDISPLAYMODEL_H
#define FILEDISPLAYMODEL_H
#include "Data.h"
#include "FileObserver.h"
#include <QAbstractItemModel>
#include <QTableView>

class FileDisplayModel : public QAbstractTableModel, public FileObserver
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
    FileDisplayModel(QLayout* layout, QObject *parent = nullptr);
    void setDataToModel(const QList<Data>& data);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QList<Data> model_data;
    QTableView* view;

    // FileObserver interface
public:
    void UpdateData(const QList<Data> &data) override;
};

#endif // FILEDISPLAYMODEL_H
