#ifndef EXAMPLECLASSSTATIC_H
#define EXAMPLECLASSSTATIC_H


class ExampleClassStatic
{
    static unsigned long mValByCopy;
    static unsigned long mValByPointer;
    static unsigned long mValByReference;

public:
    static void execCopy(const int aa);
    static void execPointer(const int *aa);
    static void execReference(const int &aa);
};

#endif // EXAMPLECLASSSTATIC_H
