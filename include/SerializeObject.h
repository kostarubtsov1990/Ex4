//
// Created by kostarubtsov1990 on 07/12/17.
//

#ifndef EX4CLIENT_SERIALIZEOBJECT_H
#define EX4CLIENT_SERIALIZEOBJECT_H

#include <fstream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include "Settings.h"

using namespace std;


class SerializeObject {
    public:
        void serializeToXML(const Settings &toSerialize, const char *fileName) {
            ofstream out (fileName);
            boost::archive::xml_oarchive outArchive(out);
            outArchive & BOOST_SERIALIZATION_NVP(toSerialize);
        }

    Settings deserializeFromXML(const char *fileName){
            std::ifstream in(fileName);
            boost::archive::xml_iarchive inArchive(in);

            Settings t;
            inArchive & BOOST_SERIALIZATION_NVP(t);
            return t;
        }
};


#endif //EX4CLIENT_SERIALIZEOBJECT_H
