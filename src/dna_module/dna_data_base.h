//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_DNA_DATA_BASE_H
#define UNTITLED_DNA_DATA_BASE_H

#include <string>
#include <map>
#include "dna_info.h"
#include "../myTools/not_found_exception.h"


class DnaDataBase{

public:

    typedef std::map <std::string , DnaInfo*>       MapNameToDna;
    typedef std::map<size_t , std::string>          MapIdToName;

    static MapNameToDna     createMap();
    static MapIdToName      createMapn();

    static DnaInfo*             findDna(size_t id) ;//throw exeption case there is no dna with this id
    static DnaInfo*             findDna(const std::string& name);//throw exeption case there is no dna with this name
    static const std::string&   findNameById(std::size_t);
    static void                 setNewDna(DnaInfo* dna);
    static void                 updateDna (const std::string & name, DnaSequence d);


private:

        //TODO change to shared pointer
    static MapNameToDna     dnaList;
    static MapIdToName      idList;

    static bool isDnaExist(size_t id) ;
    static bool isDnaExist(const std::string& name);
};

inline DnaInfo* DnaDataBase::findDna(const std::string &name)
{
    if(isDnaExist(name))
    {
        std::map <std::string , DnaInfo*> ::iterator it = dnaList.find(name);
        return it->second;
    }
    throw NotExists();
}

inline DnaInfo* DnaDataBase::findDna(size_t id)
{
    if(isDnaExist(id))
    {
        MapIdToName::iterator it = idList.find(id);
        return findDna(it->second);
    }
    throw NotExists();
}

inline bool DnaDataBase::isDnaExist(const std::string& name)
{
    MapNameToDna::iterator it = dnaList.find(name);

    return it!=dnaList.end();
}

inline bool DnaDataBase::isDnaExist(size_t id)
{
    MapIdToName::iterator it = idList.find(id);
    return (it!=idList.end()) && (isDnaExist(it->second));
}

inline void DnaDataBase::setNewDna(DnaInfo *dna)
{
    dnaList[dna->getNmae()] = dna;
    idList[dna->getId()] = dna->getNmae();
}

inline DnaDataBase::MapNameToDna DnaDataBase::createMap()
{
    MapNameToDna tmp;
    return tmp;
}

inline DnaDataBase::MapIdToName DnaDataBase::createMapn()
{
    MapIdToName tmp;
    return tmp;
}

inline const std::string& DnaDataBase::findNameById(std::size_t id)
{
    return findDna(id)->getNmae();
}

inline void DnaDataBase::updateDna(const std::string &name, DnaSequence d)
{
    findDna(name)->updateDna(d);
}
#endif //UNTITLED_DNA_DATA_BASE_H
