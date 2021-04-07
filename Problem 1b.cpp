#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Address
{
private:
    string street_name;
    int house_number;
    string city_name;
public:
    Address(string street_name, int house_number, string city_name)
        : street_name{street_name}, house_number{house_number}, city_name{city_name}
    {}
};

class Pets
{
protected:
    string name;
    int code;
public:
    Pets(){}
    virtual ~Pets(){}

    bool operator== (Pets other)
    {
        if (other.code!=this->code) return false;
        return true;
    }
};

class Dogs: public Pets
{
public:
    Dogs(string name, int code)
    {
        this->name = name;
        this->code = code;
    }

    void make_noise()
    {
        cout << "Woof!";
    }
};

class Cats: public Pets
{
public:
    Cats(string name, int code)
    {
        this->name = name;
        this->code = code;
    }

    void make_noise()
    {
        cout << "Meow!";
    }
};

class House
{
private:
    Address address;
    vector <Pets*> list_of_pets;
public:
    House(Address address)
        :address{address}
    {}
    void add_pets(Pets* pet)
    {
        list_of_pets.push_back(pet);
    }

    void remove_pets(Pets pet)
    {
        for (int i=0; i <list_of_pets.size(); i++)
        {
            if(*list_of_pets[i] == pet)
            {
                list_of_pets.erase(list_of_pets.begin()+i);
            }
        }
    }

    int count_pets()
    {
        return list_of_pets.size();
    }
};

int main(){
    Address a1("Tran Hung Dao", 69, "Ho Chi Minh");
    Address a2("CMT8", 34, "Ho Chi Minh");
    Address a3("Tran Hung Dao", 65, "Ho Chi Minh");
    Dogs d1("Kacy", 123);
    Dogs d2("Lily", 321);
    Dogs d3("Milo", 239);
    Cats d4("Khoa", 999);
    Cats d5("Bubu", 458);

    House h1(a1);
    House h2(a2);
    House h3(a3);

    h1.add_pets(&d1);
    h1.add_pets(&d2);
    h1.remove_pets(d1);
    h1.remove_pets(d2);

    h2.add_pets(&d4);

    h3.add_pets(&d3);
    h3.add_pets(&d5);
    cout << "Number of pets in house 1: " << h1.count_pets() << endl;
    cout << "Number of pets in house 2: " << h2.count_pets() << endl;
    cout << "Number of pets in house 3: " << h3.count_pets() << endl;
	return 0;
}
