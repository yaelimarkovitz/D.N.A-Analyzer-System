//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_DNA_INFO_H
#define UNTITLED_DNA_INFO_H

#include <string>
#include "dna_sequence.h"
typedef enum status{
   E_NEW,
   E_UP_TO_DATE,
   E_MODIFIED
}status;
class DnaInfo {

public:
    DnaInfo(DnaSequence*, size_t,const std::string&);

private:
    DnaSequence * m_dna;
    size_t m_id;
    std::string m_name;
    status m_st;
};

inline DnaInfo::DnaInfo(DnaSequence *dna, size_t id, const std::string & name):m_dna(dna),m_id(id),m_name(name),m_st(E_NEW) {
}


#endif //UNTITLED_DNA_INFO_H
