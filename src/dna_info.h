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
    DnaInfo(DnaSequence*,const std::string&);
    size_t getId() const;
    std::string getNmae() const;
private:
    DnaSequence * m_dna;
    size_t m_id;
    std::string m_name;
    status m_st;
    static size_t s_counterId;
    static size_t generateId();
};

inline DnaInfo::DnaInfo(DnaSequence *dna,  const std::string & name):m_dna(dna),m_id(generateId()),m_name(name),m_st(E_NEW) {
}

inline size_t DnaInfo::getId() const {
    return m_id;
}

inline std::string DnaInfo::getNmae() const {
    return m_name;
}

inline size_t DnaInfo::generateId() {
    return s_counterId++;
}


#endif //UNTITLED_DNA_INFO_H
