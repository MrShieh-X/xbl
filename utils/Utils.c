#include "Utils.h"

int statusCodeEqualsTo(int statusCode, int code) {
    return ((UINTN) statusCode) == ((UINTN) code);
}

UINTN GetValue(
        IN EFI_PHYSICAL_ADDRESS StartAddress,
        IN UINTN Offset,
        IN UINTN Size) {
    UINT8 * ByteStart = (UINT8 *) StartAddress + Offset;
    UINTN Result = 0;
    for (UINTN i = 0; i < Size; i++) {
        Result += *(ByteStart + i) << i * 8;
    }
    return Result;
}


int isPrint() {
#ifdef PRINT_LOGS
    return 1;
#else
    return 0;
#endif
}