#include "filedisplaymodel.h"
#include <QLocale>
#include <QLayout>

FileDisplayModel::FileDisplayModel(const QList<Data> &data, QObject *parent)
    : QAbstractTableModel{parent}
{
    model_data = data;
}

FileDisplayModel::FileDisplayModel(QLayout *layout, QObject *parent) : QAbstractTableModel{parent}
{
    view = new QTableView();
    view->setModel(this);
    layout->addWidget(view);
}

void FileDisplayModel::setDataToModel(const QList<Data> &data)
{
    beginResetModel();
    model_data = data;
    endResetModel();
}


int FileDisplayModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return model_data.count();
}

int FileDisplayModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return int(ColumnName::PERCENT) + 1;
}

QVariant FileDisplayModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || model_data.count() <= index.row() || (role != Qt::DisplayRole && role != Qt::EditRole)) {
        return QVariant();
    }
    switch (index.column()) {
    case 0: return model_data[index.row()].name_;
    case 1:
    {
        QLocale locale(QLocale::English);
        return locale.formattedDataSize(model_data[index.row()].size_);
    }
    case 2: {
        if (model_data[index.row()].percent_ < 0)
            return "< 0.01 %";
        else return QString::number(model_data[index.row()].percent_, 'f', 2) + " %";
    }
    default: return QVariant();
    }
}

QVariant FileDisplayModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Vertical) {
        return section;
    }
    switch (section) {
    case int(ColumnName::NAME):
        return QString::fromUtf8("Название");
    case int(ColumnName::SIZE):
        return QString::fromUtf8("Размер");
    case int(ColumnName::PERCENT):
        return QString::fromUtf8("Процент");
    }
    return QVariant();
}


void FileDisplayModel::UpdateData(const QList<Data> &data)
{
    this->setDataToModel(data);
}
