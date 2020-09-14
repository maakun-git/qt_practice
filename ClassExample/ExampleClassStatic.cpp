#include "ExampleClassStatic.h"

unsigned long ExampleClassStatic::mValByCopy = 0;
unsigned long ExampleClassStatic::mValByPointer = 0;
unsigned long ExampleClassStatic::mValByReference = 0;


void ExampleClassStatic::execCopy(const int aa)
{
    mValByCopy += aa;
}

void ExampleClassStatic::execPointer(const int *aa)
{
    mValByPointer += *aa;
}

void ExampleClassStatic::execReference(const int &aa)
{
    mValByReference += aa;
}
