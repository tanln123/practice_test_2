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

class Dogs
{
private:
    string name;
    int dog_code;
public:
    Dogs(string name, int dog_code)
        :name{name}, dog_code{dog_code}
    {}

    bool operator== (Dogs other)
    {
        if(other.dog_code == this->dog_code) return true;
        return false;
    }

    void make_noise()
    {
        cout << "Woof!";
    }
};

class House
{
private:
    Address address;
    vector <Dogs> pets;
public:
    House(Address address)
        :address{address}
    {}

    void add_dog(Dogs dog)
    {
        pets.push_back(dog);
    }

    void remove_dog(Dogs dog)
    {
        for (int i= 0; i <= pets.size(); i++)
        {
            if (pets[i] == dog)
            {
                pets.erase(pets.begin()+i);
            }
        }
    }

    int count_dog()
    {
        return pets.size();
    }
};

int main(){
    Address a1("Tran Hung Dao", 69, "Ho Chi Minh");
    Address a2("CMT8", 34, "Ho Chi Minh");
    Address a3("Tran Hung Dao", 65, "Ho Chi Minh");
    Dogs d1("Kacy", 123);
    Dogs d2("Lily", 321);
    Dogs d3("Milo", 239);
    Dogs d4("Khoa", 999);
    Dogs d5("Bubu", 458);

    House h1(a1);
    House h2(a2);
    House h3(a3);

    h1.add_dog(d1);
    h1.add_dog(d2);

    h1.remove_dog(d1);

    h3.add_dog(d3);
    h3.add_dog(d5);
    cout << "Number of dogs in house 1: " << h1.count_dog() << endl;
    cout << "Number of dogs in house 2: " << h2.count_dog() << endl;
    cout << "Number of dogs in house 3: " << h3.count_dog() << endl;
	return 0;
}
