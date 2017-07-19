// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "Data/DynamicJsonBuffer.hpp"
#include "JsonArray.hpp"

namespace ArduinoJson {

class DynamicJsonArray : public JsonArray {
  Internals::DynamicJsonBuffer _buffer;

 public:
  DynamicJsonArray() : JsonArray(&_buffer) {}

  DynamicJsonArray(const DynamicJsonArray& other) : JsonArray(&_buffer) {
    JsonArray::operator=(other);
  }

  DynamicJsonArray(const JsonArray& other) : JsonArray(&_buffer) {
    JsonArray::operator=(other);
  }

  using JsonArray::operator=;

  DynamicJsonArray& operator=(const DynamicJsonArray& other) {
    JsonArray::operator=(other);
    return *this;
  }

  Internals::DynamicJsonBuffer& buffer() {
    return _buffer;
  }
};
}
