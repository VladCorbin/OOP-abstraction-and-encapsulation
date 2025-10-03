#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

class Address 
{
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    Address(const std::string& c, const std::string& s, int h, int a)
        : city(c), street(s), house(h), apartment(a) {}

    std::string get_output_address() const 
    {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream inFile("in.txt");
    std::ofstream outFile("out.txt");

    if (!inFile.is_open() || !outFile.is_open()) 
    {
        std::cerr << "Ошибка открытия файлов" << std::endl;
        return 1;
    }

    int n;
    inFile >> n;
    outFile << n << std::endl;

    Address** addresses = new Address* [n];

    for (int i = 0; i < n; ++i) 
    {
        std::string city, street;
        int house, apartment;

        inFile >> city;
        inFile >> street;
        inFile >> house;
        inFile >> apartment;

        addresses[i] = new Address(city, street, house, apartment);
    }

    for (int i = n - 1; i >= 0; --i) 
    {
        outFile << addresses[i]->get_output_address() << std::endl;
    }

    for (int i = 0; i < n; ++i) { delete addresses[i]; }

    delete[] addresses;

    
    inFile.close();
    outFile.close();

    return EXIT_SUCCESS;
}
