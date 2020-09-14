//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_DNA_DATA_BASE_H
#define UNTITLED_DNA_DATA_BASE_H

#include <string>
#include <map>
#include "dna_info.h"
#include "../SharedPointer.h"

class DnaDataBase{

public:

    typedef std::map <std::string , DnaInfo*>       MapNameToDna;
    typedef std::map<size_t , std::string>          MapIdToName;

    static MapNameToDna     createMap();
    static MapIdToName      createMapn();

    static DnaInfo*     findById(size_t id) ;//return nullptr case there is no dna with that name
    static DnaInfo*     findByName(const std::string& name);//return nullptr case there is no dna with that id
    static void         setNewDna(DnaInfo* dna);//TODO check it insert params to this function


private:

        //TODO change to shared pointer
    static MapNameToDna     dnaList;
    static MapIdToName      idList;

    static bool isDnaExist(size_t id) ;
    static bool isDnaExist(const std::string& name);
};

inline DnaInfo* DnaDataBase::findByName(const std::string &name)
{
    if(isDnaExist(name))
    {
        std::map <std::string , DnaInfo*> ::iterator it = dnaList.find(name);
        return it->second;
    }
    return NULL;
}

inline DnaInfo* DnaDataBase::findById(size_t id)
{
    if(isDnaExist(id))
    {
        MapIdToName::iterator it = idList.find(id);
        return findByName(it->second);
    }
    return NULL;
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
#endif //UNTITLED_DNA_DATA_BASE_H
