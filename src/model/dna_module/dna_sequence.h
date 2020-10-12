#include <cstring>
#include <string>
#include <iostream>
#include <exception>
#include <cstdio>
#include <vector>
#include "my_exception.h"
#include "../myTools/readers/IReader.h"
#include "../myTools/writers/IWrither.h"


class DnaSequence{
    
private:

    mutable size_t m_length_dna;

    class Nucleotide{

    public:
        Nucleotide(){}
        Nucleotide      (const char &c);
        Nucleotide      (const Nucleotide &n);
        Nucleotide&     operator=(Nucleotide &n);
        bool            operator==(const Nucleotide& n)const;
        bool            operator!=(const Nucleotide& n)const;
        char            getChar()const;

    private:
        void            isValid(const char &c)const ;
        char            m_nuc;
    };

    Nucleotide *        m_dna_seq;
    void                init( char *seq);
    void                copy(const DnaSequence & d);

public:
    DnaSequence(){};
    DnaSequence( char* seq);
    DnaSequence(const std::string &seq);
    DnaSequence(const DnaSequence& d);
    DnaSequence(IReader*);

    const DnaSequence&      operator=(const DnaSequence& d);
    const DnaSequence&      operator+=(DnaSequence& d);
    const size_t            length() const;
    bool                    compare(const DnaSequence& d) const;
    const Nucleotide&       operator[]( size_t index) const ;
    Nucleotide&             operator[]( size_t index);
    DnaSequence             slice(int start,int end);
    void                    replace(int index, char letter);
    DnaSequence             pair() const ;
    int                     find(const DnaSequence d)const ;
    int                     count(const DnaSequence d)const ;
    std::vector <int>       findAll(const DnaSequence d) const ;
    std::vector <int>       findConsensusSequences() const ;
    int                     input(const char* name_file);
    void                    output(IWriter*) const;
    std::string             toStr()const;

};

inline DnaSequence::DnaSequence( char *seq):m_length_dna(strlen(seq)),m_dna_seq(new Nucleotide[m_length_dna])
{
        init(seq);
}
inline DnaSequence::DnaSequence(const std::string &seq): m_length_dna(seq.size()), m_dna_seq(new Nucleotide[m_length_dna])
{
        init(const_cast<char*>(seq.c_str()));
}

inline void DnaSequence::copy(const DnaSequence& d )
{
    for (unsigned int i = 0; i <m_length_dna ; ++i)
    {
        Nucleotide n(d[i]);
        m_dna_seq[i]=n;
    }
}

inline DnaSequence::DnaSequence(const DnaSequence &d): m_length_dna(d.length()), m_dna_seq(new Nucleotide [m_length_dna])
{
    copy(d);
}

inline DnaSequence::DnaSequence(IReader * reader)
{
    std::string input = reader->read();
    m_length_dna = input.size()-1;
    m_dna_seq = new Nucleotide[m_length_dna];
    const char * buffer =input.c_str();
    init(const_cast<char*>(buffer));
}

inline const DnaSequence& DnaSequence:: operator=(const DnaSequence& d){
    Nucleotide * orig = m_dna_seq;
    m_dna_seq = new Nucleotide [d.length()];
    delete [] orig;
    m_length_dna= d.length();
    copy(d);
    return *this;
}

inline const DnaSequence& DnaSequence::operator+=(DnaSequence &d)
{
    Nucleotide * new_seq = new Nucleotide[m_length_dna+d.length()];

    for (int i = 0; i < m_length_dna; ++i)
    {
        new_seq[i] = m_dna_seq[i];
    }
    for (int j = 0; j < d.length(); ++j)
    {
        new_seq[m_length_dna+j] = d[j];
    }

    m_length_dna += d.length();
    delete m_dna_seq;
    m_dna_seq = new_seq;
    return *this;

}
inline std::ostream& operator<<(std::ostream& cout,const DnaSequence &d)
{
    for (unsigned int i = 0; i < d.length(); ++i)
    {
        cout<<d[i].getChar()<<"";
    }
    return cout;
}

inline bool operator ==(const DnaSequence &d1,const DnaSequence &d2)
{
    return (d1.compare(d2));
}
inline bool operator !=(const DnaSequence &d1,const DnaSequence &d2)
{
    return (d1.compare(d2));
}

inline const size_t DnaSequence:: length() const
{
    return m_length_dna;
}

inline DnaSequence::Nucleotide& DnaSequence:: operator[]( size_t index)
{
    if (index>m_length_dna )
    {
        throw TooLargIndex();
    }
    return m_dna_seq[index];
}

inline const DnaSequence::Nucleotide& DnaSequence:: operator[]( size_t index) const{
    if (index>m_length_dna )
    {
        throw TooLargIndex();
    }
    return m_dna_seq[index];
}

inline std::string DnaSequence::toStr() const {
    std::string tmp;
    for (unsigned int i = 0; i < m_length_dna; ++i)
    {
        tmp.push_back(m_dna_seq[i].getChar());
    }
    return tmp;
}

inline DnaSequence operator+(const DnaSequence& d1, const DnaSequence& d2)
{
    DnaSequence newDna = d1;
    newDna += const_cast< DnaSequence& >(d2);
    return newDna;
}
////////nuclutide class/////////////////////////////
inline char DnaSequence::Nucleotide::getChar() const
{
    return m_nuc;
}

inline  bool DnaSequence::Nucleotide::operator==(const Nucleotide &n) const
{
    return m_nuc==n.m_nuc;
}

inline  bool DnaSequence::Nucleotide::operator!=(const Nucleotide &n) const
{
    return m_nuc!=n.m_nuc;
}

inline DnaSequence::Nucleotide::Nucleotide(const char &c):m_nuc(c)
{
    isValid(c);
}

inline DnaSequence::Nucleotide::Nucleotide(const Nucleotide &n):m_nuc(n.getChar()) {
}

inline  DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator=(Nucleotide &n)
{
    m_nuc=n.getChar();
    return *this;
}

inline void DnaSequence::Nucleotide::isValid(const char& c)const
{
    if (c != 'C' && c != 'T' && c != 'G' && c != 'A')
    {
        throw InVailidNeculeotide();
    }
}
