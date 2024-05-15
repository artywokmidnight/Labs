#include <iostream>
#include <cmath>
//another comment
class Array
{
public:
    double* arr;
    int s;

    double& operator[](int ind)
    {
        return arr[ind];
    }

    Array() { s = 0; }

    ~Array() { delete[] arr; }

    Array(int size)
    {
        s = size;

        arr = new double[s];
    }

    void reading()
    {
        for (int i = 0; i < s; i++)
            std::cin >> arr[i];
    }


    double sum(double opF, double opS)
    {
        return opF + opS;
    }

    double difference(double opF, double opS)
    {
        return opF - opS;
    }

    double multi(double opF, double opS)
    {
        return opF * opS;
    }

    double div(double opF, double opS)
    {
        return opF / opS;
    }

    void toodisplay(Array& first, Array& second)
    {
        std::cout << "summa = ";

        for (int i = 0; i < s; i++)
            std::cout << " " << sum(first[i], second[i]);

        std::cout << std::endl;

        std::cout << "raznost=";

        for (int i = 0; i < s; i++)
            std::cout << " " << difference(first[i], second[i]);

        std::cout << std::endl;

        std::cout << "proizv=";

        for (int i = 0; i < s; i++)
            std::cout << " " << multi(first[i], second[i]);

        std::cout << std::endl;

        std::cout << "delenie=";

        for (int i = 0; i < s; i++)
            std::cout << " " << div(first[i], second[i]);

        std::cout << std::endl;
    }

    void NumMulti(Array& first, Array& sec)
    {
        double number = 0;

        std::cin >> number;

        for (int i = 0; i < s; i++)
            first[i] = multi(first[i], number);

        for (int i = 0; i < s; i++)
            sec[i] = multi(sec[i], number);

        std::cout << std::endl << "mult chislo massiv1=";

        for (int i = 0; i < s; i++)
            std::cout << " " << first[i];

        std::cout << std::endl << "mult chislo massiv2=";

        for (int i = 0; i < s; i++)
            std::cout << " " << sec[i];

        std::cout << std::endl;
    }

    void equalchecker(Array& first, Array& sec)
    {
        bool check = false;

        for (int i = 0; i < s; i++)
        {
            if (first[i] != sec[i])
            {
                std::cout << std::endl << "massivy ne ravny";

                check = false;

                break;
            }
            else
            {
                check = true;
            }
        }

        if (check == true)
        {
            std::cout << std::endl << "massivy ravny";
        }
    }
};

int main()
{
    int size;

    std::cin >> size;

    Array arrfirst(size);
    Array arrsec(size);

    arrfirst.reading();

    arrsec.reading();

    std::cout << "massiv1= ";

    for (int i = 0; i < size; i++)
        std::cout << arrfirst[i] << "  ";

    std::cout << std::endl;

    std::cout << "massiv2= ";
    for (int i = 0; i < size; i++)
        std::cout << arrsec[i] << "  ";

    std::cout << std::endl;

    arrsec.toodisplay(arrfirst, arrsec);

    arrsec.NumMulti(arrfirst, arrsec);

    arrsec.equalchecker(arrfirst, arrsec);

    return 0;
}
