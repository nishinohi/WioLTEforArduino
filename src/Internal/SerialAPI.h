#pragma once

#include <Arduino.h>

class SerialAPI {
  private:
    HardwareSerial *_Serial;

  public:
    SerialAPI(HardwareSerial *serial) : _Serial(serial) {}
    void Begin(int baud = 115200) { _Serial->begin(baud); }
    void Begin(uint8_t rxPin, uint8_t txPin, int baud = 115200) {
        _Serial->begin(baud, SERIAL_8N1, rxPin, txPin);
    }
    void Write(byte data) { _Serial->write(data); }
    bool Available() const { return _Serial->available() >= 1 ? true : false; }
    byte Read() { return _Serial->read(); }
    void Flush() { _Serial->flush(); }
};
