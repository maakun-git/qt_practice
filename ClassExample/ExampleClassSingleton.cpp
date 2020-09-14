#include "ExampleClassSingleton.h"

ExampleClassSingleton ExampleClassSingleton::m_instance = ExampleClassSingleton();

ExampleClassSingleton::ExampleClassSingleton():
    mValByCopy(0),
    mValByPointer(0),
    mValByReference(0)
{

}

ExampleClassSingleton &ExampleClassSingleton::getInstance()
{
    return m_instance;
}

void ExampleClassSingleton::execCopy(const int aa)
{
    mValByCopy += aa;
}

void ExampleClassSingleton::execPointer(const int *aa)
{
    mValByPointer += *aa;
}

void ExampleClassSingleton::execReference(const int &aa)
{
    mValByReference += aa;
}
