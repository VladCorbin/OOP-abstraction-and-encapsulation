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


    const std::string& get_city() const { return city; }

};

void sort(Address** addresses, int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (addresses[j]->get_city() > addresses[j + 1]->get_city()) 
            {
                // Меняем местами
                Address* temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
            }
        }
    }
}

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

    sort(addresses, n);

    for (int i = 0; i < n; ++i) 
    {
        outFile << addresses[i]->get_output_address() << std::endl;
    }

    for (int i = 0; i < n; ++i) { delete addresses[i]; }

    delete[] addresses;

    
    inFile.close();
    outFile.close();

    return EXIT_SUCCESS;
}
