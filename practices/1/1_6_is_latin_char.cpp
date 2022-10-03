//
// Created by yawkar on 03.10.22.
//

#include "1_6_is_latin_char.h"

bool isLatin(char character) {
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}
