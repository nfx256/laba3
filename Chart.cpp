#include "Chart.h"

Chart::Chart(QLayout *layout)
{
    chart_model = new QChart;
    chart_view = new QChartView;
    chart_view->setChart(chart_model);
    chart_model->legend()->setAlignment(Qt::AlignRight);
    layout->addWidget(chart_view);
}

void Chart::SetDataChart(const QList<Data> &data)
{
    chart_model->setTitle("");
    qint64 folder_size = 0;
    for (auto& x : data) {
        folder_size += x.size_;
    }
    if (folder_size == 0) {
        chart_model->setTitle("Folder is empty");
        chart_model->removeAllSeries();
        return;
    }
    if (data.size() > 8)
    {
        QList<Data> chart_data;
        qint64 others = 0;
        for (int i = 0; i < 8; i++)
        {
            chart_data.push_back(data.at(i));
        }
        for (int i = 8; i < data.size(); i++)
        {
            others += data.at(i).size_;
        }
        chart_data.push_back(Data("Others", others,
                                  (qreal)others * 100 / folder_size));
        SetDataToChart(chart_data);
    } else {
        SetDataToChart(data);
    }
}

void Chart::UpdateData(const QList<Data> &data)
{
    SetDataChart(data);
}

void Chart::SetDataToChart(const QList<Data> &data) const
{
    chart_model->removeAllSeries();
    chart_model->addSeries(DataToSeries(data));
}

BarChart::BarChart(QLayout* layout) : Chart(layout) {}

QAbstractSeries *BarChart::DataToSeries(const QList<Data> &data) const
{
    QBarSeries* bar_series = new QBarSeries();
    bar_series->setBarWidth(1);
    for (auto& x : data) {
        if (x.percent_ < 0) {
            QBarSet* set = new QBarSet(x.name_ + QString("(< 0.01 %)").toHtmlEscaped());
            set->append(std::abs(x.percent_));
            bar_series->append(set);
        } else {
            QBarSet* set = new QBarSet(x.name_ + "(" + QString::number(x.percent_, 'f', 2) + " %)");
            set->append(x.percent_);
            bar_series->append(set);
        }
    }
    return bar_series;
}

PieChart::PieChart(QLayout* layout) : Chart(layout) {}

QAbstractSeries *PieChart::DataToSeries(const QList<Data> &data) const
{
    QPieSeries* pie_series = new QPieSeries();
    pie_series->setPieSize(1);
    for (auto& item : data) {
        if (item.percent_ < 0) {
            pie_series->append(item.name_ + QString("(< 0.01 %)")
                           .toHtmlEscaped(), std::abs(item.percent_));
        } else {
            pie_series->append(item.name_ + "(" + QString::number(item.percent_,
                            'f', 2) + " %)", item.percent_);
        }
    }
    return pie_series;
}
