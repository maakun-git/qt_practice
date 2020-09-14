#ifndef EXAMPLECLASSSINGLETON_H
#define EXAMPLECLASSSINGLETON_H


class ExampleClassSingleton
{
private:
    ExampleClassSingleton();
    static ExampleClassSingleton m_instance;

    unsigned long mValByCopy;
    unsigned long mValByPointer;
    unsigned long mValByReference;

public:
    static ExampleClassSingleton& getInstance();

    void execCopy(const int aa);
    void execPointer(const int *aa);
    void execReference(const int &aa);
};

#endif // EXAMPLECLASSSINGLETON_H
