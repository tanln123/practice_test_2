#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Club
{
private:
    string name;
    string building;
    long int phone;
public:
    Club(string name, string building, long int phone)
        :name{name}, building{building}, phone{phone}
    {}
};

class Campus
{
private:
    Club club;
    string name;
    string address;
    double distance;
public:
    Campus(Club club, string name, string address, double distance)
        :club{club}, name{name}, address{address}, distance{distance}
    {}
};

class Lecturer
{
private:
    int id;
    string name;
    string title;
    int office_room;
public:
    Lecturer(int id, string name, string title, int office_room)
        : id{id}, name{name}, title{title}, office_room{office_room}
    {}
};

class University
{
private:
    vector <Lecturer> list_of_lecturer;
    vector <Campus> list_of_campus;
public:
    University(){}
    ~University(){}
};

int main(){

	return 0;
}
