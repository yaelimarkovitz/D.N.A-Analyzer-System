//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_DNA_DATA_BASE_H
#define UNTITLED_DNA_DATA_BASE_H

#include <string>
#include <map>
#include "dna_info.h"

class DnaDataBase{

public:

    static DnaInfo* findById(size_t id) ;//return nullptr case there is no dna with that name
    static DnaInfo* findByName(const std::string& name);//return nullptr case there is no dna with that id
    static void setNewDna(DnaSequence * d);//TODO check it insert params to this function

private:

    static std::map<std::string, DnaInfo*> dnaList;
    static std::map<size_t,std::string> idList;
    static bool isDnaExist(size_t id) ;
    static bool isDnaExist(const std::string& name);
};

inline DnaInfo* DnaDataBase::findByName(const std::string &name){
    if(isDnaExist(name)){
        std::map<std::string , DnaInfo*>::iterator it = dnaList.find(name);
        return it->second;
    }
    return NULL;
}

inline DnaInfo* DnaDataBase::findById(size_t id) {
    if(isDnaExist(id)) {
        std::map<size_t, std::string>::iterator it = idList.find(id);
        return findByName(it->second);
    }
    return NULL;
}

inline bool DnaDataBase::isDnaExist(const std::string& name) {
    std::map<std::string , DnaInfo*>::iterator it = dnaList.find(name);
    return it!=dnaList.end();
}

inline bool DnaDataBase::isDnaExist(size_t id)  {
    std::map<size_t, std::string>::iterator it = idList.find(id);
    return (it!=idList.end()) && (isDnaExist(it->second));
}

#endif //UNTITLED_DNA_DATA_BASE_H
