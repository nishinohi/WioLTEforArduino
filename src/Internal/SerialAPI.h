#pragma once

#include <Arduino.h>

class SerialAPI {
  private:
    HardwareSerial *_Serial;
    int _baud;
    uint8_t _rxPin;
    uint8_t _txPin;

  public:
    SerialAPI(HardwareSerial *serial, int baud, uint8_t rxPin, uint8_t txPin)
        : _Serial(serial), _baud(baud), _rxPin(rxPin), _txPin(txPin) {}
    void Begin(int baud) { _Serial->begin(baud); }
    void Begin(int baud, uint8_t rxPin, uint8_t txPin) {
        _Serial->begin(baud, SERIAL_8N1, rxPin, txPin);
    }
    void Write(byte data) { _Serial->write(data); }
    bool Available() const { return _Serial->available() >= 1 ? true : false; }
    byte Read() { return _Serial->read(); }
    void Flush() { _Serial->flush(); }
};
