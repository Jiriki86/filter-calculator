#include <QObject>
#include <qqml.h>

class FilterCalculator : public QObject {
  Q_OBJECT
  QML_ELEMENT

  Q_PROPERTY(double res READ res WRITE setRes NOTIFY resChanged);
  Q_PROPERTY(double cap READ cap WRITE setCap NOTIFY capChanged);
  Q_PROPERTY(double cutOff READ cutOff WRITE setCutOff NOTIFY cutOffChanged);

public:
  enum FilterType { LowPass, HighPass };
  Q_ENUM(FilterType)

  enum CalculationMode { Cutoff, Capacitance, Resistance };
  Q_ENUM(CalculationMode)

  Q_PROPERTY(FilterType filterType READ filterType WRITE setFilterType NOTIFY
                 filterTypeChanged);

  FilterCalculator(QObject *parent = nullptr);

public slots:
  double res() const;
  double cap() const;
  double cutOff() const;

  void setRes(double r);
  void setCap(double c);
  void setCutOff(double f);

  void calculate();

  void setFilterType(QString filterType);
  FilterType filterType() const;
  void setFilterType(FilterType f);

  void setCalculationMode(CalculationMode mode);

signals:
  void resChanged(double val);
  void capChanged(double val);
  void cutOffChanged(double val);
  void filterTypeChanged(FilterType f);

private:
  double m_res = 0;
  double m_cap = 0;
  double m_cutOff = 0;

  FilterType m_filterType = FilterType::LowPass;
  CalculationMode m_calculationMode = CalculationMode::Cutoff;
};
