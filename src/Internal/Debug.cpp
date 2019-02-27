#include "Debug.h"
#include "../WioLTEConfig.h"

#ifdef WIO_DEBUG

void Debug::Print(const char *str) {
    for (int i = 0; i < strlen(str); i++)
        Serial.print(str[i]);
}

void Debug::Println(const char *str) {
    Print(str);
    Print("\r\n");
}

#endif // WIO_DEBUG
