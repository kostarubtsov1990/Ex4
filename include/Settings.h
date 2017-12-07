//
// Created by kostarubtsov1990 on 07/12/17.
//

#ifndef EX4CLIENT_SETTINGS_H
#define EX4CLIENT_SETTINGS_H

#include <string>
#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>
#include <iostream>

using namespace std;

class Settings {
public:
    Settings(): domain_name(""), port(0) {}
    Settings(const string &name, int age): domain_name(name), port(age) {}
private:
    string domain_name;
    int port;
    // Allow serialization to access non-public data members
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, unsigned int version) {
        ar & BOOST_SERIALIZATION_NVP(domain_name) & BOOST_SERIALIZATION_NVP(port); // Serialize the data members of Student
    }
    /*friend ostream& operator <<(ostream &out, const Settings &s) {
        return out << s.domain_name << ", age: " << s.port;
    }*/
};
#endif //EX4CLIENT_SETTINGS_H
