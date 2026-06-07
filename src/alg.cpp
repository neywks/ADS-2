// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double res = 1.0;
  for (uint16_t i = 0; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double res = 0.0;
  for (uint16_t i = 0; i <= count; ++i) {
    res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0.0;
  for (uint16_t i = 1; i <= count; ++i) {
    double sign = (i % 2 == 0) ? -1.0 : 1.0;
    double term = pown(x, 2 * i - 1) / fact(2 * i - 1);
    res += sign * term;
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 0.0;
  for (uint16_t i = 0; i <= count; ++i) {
    double sign = (i % 2 == 0) ? 1.0 : -1.0;
    if (i == 0) {
      res += 1.0;
    } else {
      double term = pown(x, 2 * i) / fact(2 * i);
      res += sign * term;
    }
  }
  return res;
}
