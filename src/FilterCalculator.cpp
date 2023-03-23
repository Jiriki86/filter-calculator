#include "FilterCalculator.h"

#include <cmath>
#include <iostream>

FilterCalculator::FilterCalculator(QObject *parent) : QObject(parent) {}

double FilterCalculator::res() const { return m_res; }
double FilterCalculator::cap() const { return m_cap; }
double FilterCalculator::cutOff() const { return m_cutOff; }

void FilterCalculator::setRes(double r) {
  if (r != m_res) {
    m_res = r;
    emit resChanged(m_res);
  }
}

void FilterCalculator::setCap(double c) {
  if (c != m_cap) {
    m_cap = c;
    emit capChanged(m_cap);
  }
}

void FilterCalculator::setCutOff(double f) {
  if (f != m_cutOff) {
    m_cutOff = f;
    emit cutOffChanged(m_cutOff);
  }
}

constexpr double TWOPI = 2. * M_PI;

void FilterCalculator::calculateCutOff() {
  if (m_res < 1e-3 || m_cap < 1e-3) {
    return;
  }

  m_cutOff = 1. / (TWOPI * m_res * m_cap * 1e-6);
  emit cutOffChanged(m_cutOff);
}

void FilterCalculator::setFilterType(QString filterType) {
  if (filterType == "Low Pass") {
    setFilterType(FilterType::LowPass);
  } else if (filterType == "High Pass") {
    setFilterType(FilterType::HighPass);
  } else {
    std::cout << "Warning: Received unknown filter type\n";
  }
}

FilterCalculator::FilterType FilterCalculator::filterType() const {
  return m_filterType;
}

void FilterCalculator::setFilterType(FilterType f) {
  if (f != m_filterType) {
    m_filterType = f;
    emit filterTypeChanged(m_filterType);
  }
}
