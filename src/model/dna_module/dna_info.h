//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_DNA_INFO_H
#define UNTITLED_DNA_INFO_H

#include <string>
#include <sstream>
#include "dna_sequence.h"
typedef enum status{
   E_NEW,
   E_UP_TO_DATE,
   E_MODIFIED
}status;

class DnaInfo {

public:

    DnaInfo(DnaSequence,const std::string&);

    size_t                  getId() const;
    const std::string &     getNmae() const;
    DnaSequence             getDna() const ;
    int                     getStatus()const;
    void                    updateDna( DnaSequence d);
    void                    updateName(const std::string& newName);
    void                    setStatus(status s);
    std::string             getInfo();
    std::string             getInfoWithStatus(size_t numOfChars = 99);

private:

    DnaSequence     m_dna;
    size_t          m_id;
    std::string     m_name;
    status          m_st;
    static size_t   s_counterId;
    std::vector<std::string> m_status;
    static size_t   generateId();
};

inline DnaInfo::DnaInfo(DnaSequence dna,  const std::string & name):
                    m_dna(dna),
                    m_id(generateId()),
                    m_name(name),
                    m_st(E_NEW)
{
    m_status.push_back("new");
    m_status.push_back("up_to_date");
    m_status.push_back("modified");
}

inline size_t DnaInfo::getId() const
{
    return m_id;
}

inline const std::string & DnaInfo::getNmae() const
{
    return m_name;
}

inline int DnaInfo::getStatus() const
{
    return m_st;
}

inline DnaSequence DnaInfo::getDna() const
{
    return m_dna;
}

inline size_t DnaInfo::generateId()
{
    return s_counterId++;
}

inline std::string DnaInfo::getInfo()
{
    std::ostringstream ss ;
    ss << m_id;
    std::string tmp;
    for (unsigned int i = 0; i < m_dna.length(); ++i)
    {
        tmp.push_back(m_dna[i].getChar());
    }
    return "[" + ss.str()+ "] " + m_name + ": " + tmp;
}

inline std::string DnaInfo::getInfoWithStatus(size_t numOfChars) //todo extract to other func
{
    std::ostringstream ss ;
    ss << m_id;
    std::string tmp;
    puts("hi");
    for (unsigned int i = 0; i < m_dna.length(); ++i)
    {
        puts("hi");
        if (i == numOfChars)
        {
            tmp.push_back('\n');
            numOfChars += numOfChars;
        }
        tmp.push_back(m_dna[i].getChar());
    }
    return "[" + ss.str()+ "] " + m_name + " "+ m_status[m_st] +"\n"+ tmp;
}

inline void DnaInfo::updateDna(DnaSequence d)
{
    m_dna = d;
}

inline void DnaInfo::updateName(const std::string &newName)
{
    m_name = newName;
}

inline void DnaInfo::setStatus(status s) {
    m_st = s;
}
#endif //UNTITLED_DNA_INFO_H
