#pragma once
#include <cstddef>

struct TokenPosition {
  size_t start = 0;
  size_t end = 0;
  TokenPosition() {}
  TokenPosition(size_t start, size_t end) {
    this->start = start;
    this->end = end;
  }
};