#ifndef CHART_H
#define CHART_H
#include "FileObserver.h"
#include "Data.h"
#include "QtCharts"


class Chart : public FileObserver
{

public:
    Chart() = default;
    Chart(QLayout *layout);
    void SetDataChart(const QList<Data>& data);
    // FileObserver interface
    void UpdateData(const QList<Data> &data) override;
    void SetDataToChart(const QList<Data>& data) const;
    virtual QAbstractSeries* DataToSeries(const QList<Data>& data) const = 0;
    virtual ~Chart() {}
private:
    QChart* chart_model;
    QChartView* chart_view;
};


class BarChart : public Chart
{
public:
    explicit BarChart(QLayout* layout);
    // Chart interface
    QAbstractSeries *DataToSeries(const QList<Data> &data) const override;
};

class PieChart : public Chart
{
public:
    explicit PieChart(QLayout* layout);
    // Chart interface
    QAbstractSeries *DataToSeries(const QList<Data> &data) const override;
};

#endif // CHART_H
