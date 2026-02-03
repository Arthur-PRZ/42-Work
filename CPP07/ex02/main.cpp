#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> arrInt(5);

    std::cout << "Remplissage du tableau d'int..." << std::endl;
    for (unsigned int i = 0; i < arrInt.size(); i++)
        arrInt[i] = i * 10;

    std::cout << "Contenu du tableau d'int : ";
    for (unsigned int i = 0; i < arrInt.size(); i++)
        std::cout << arrInt[i] << " ";
    std::cout << std::endl;

    try {
        std::cout << "Test index hors limite : " << arrInt[10] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    Array<std::string> arrStr(3);
    arrStr[0] = "Hello";
    arrStr[1] = "CPP07";
    arrStr[2] = "42";

    std::cout << "Contenu du tableau de str : ";
    for (unsigned int i = 0; i < arrStr.size(); i++)
        std::cout << arrStr[i] << " ";
    std::cout << std::endl;

    Array<std::string> arrCopy(arrStr);
    std::cout << "Contenu de arrCopy (copie de arrStr) : ";
    for (unsigned int i = 0; i < arrCopy.size(); i++)
        std::cout << arrCopy[i] << " ";
    std::cout << std::endl;

    Array<int> arrAssign;
    arrAssign = arrInt;
    std::cout << "Contenu de arrAssign (après assignation) : ";
    for (unsigned int i = 0; i < arrAssign.size(); i++)
        std::cout << arrAssign[i] << " ";
    std::cout << std::endl;

    return 0;
}
