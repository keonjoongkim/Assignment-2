#include <string.c>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){
    const PtrToConstEmployee endPtr = Ptr + tableSize;

    for(; ptr < endPtr; ptr++)
    {
        if(ptr->number == targetNumber)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

PtrToEmployee searchEmployeeNyName(PtrToConstEmployee ptr, int tablesize, char* targetName){
    const PtrToConstEmployee endPtr = ptr + tableSize
    
    for(; ptr < endPtr; ptr++)
    {
        if(strcmp(ptr->name,targetName) == 0)
            return (PtrToEmployee) ptr;
    }
    return NULL;

}