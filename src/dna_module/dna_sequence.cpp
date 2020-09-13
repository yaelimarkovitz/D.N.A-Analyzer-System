#include "dna_sequence.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>



int DnaSequence::input(const char *name_file) {
    std::ofstream obj_file;
    obj_file.open(name_file,std::ios::app);
    obj_file.write((char*)&(*this), sizeof(DnaSequence));
    obj_file.close();
    return 0;
}
int DnaSequence::count(const DnaSequence d) const {
    size_t len1 = m_length_dna;
    size_t len2 = d.length();
    int mone=0;
    DnaSequence tmp(*this);
    int ind;
    int i =0;
    while (i < (int)(len1-len2)){
        ind = tmp.find(d);
        if(ind ==-1)
        {
            break;
        } else{
            mone++;
            i=int(ind+len2);
            tmp=tmp.slice(i,(int)tmp.length());
        }
    }
    return mone;
}
std::vector<int> DnaSequence::findAll(const DnaSequence d) const {
    size_t len1 = m_length_dna;
    size_t len2 = d.length();
    DnaSequence tmp(*this);
    std::vector<int> indexes ;
    int ind;
    int i =0;
    while (i < (int)(len1-len2)){
        ind = tmp.find(d);
        if(ind ==-1)
        {
            break;
        } else{
            indexes.push_back(ind);
            i=int(ind+len2);
            tmp = tmp.slice(i,(int)tmp.length());
        }
    }
    return indexes;
}
 void DnaSequence::init ( char * seq){
    try {
        for (unsigned int i = 0; i < m_length_dna; ++i) {
            Nucleotide n(seq[i]);
            m_dna_seq[i]=n;
        }
    }
    catch(InVailidNeculeotide &e)
    {
        std::cout<<"there is problem with your input sorry";
        throw ;
    }
}
 bool DnaSequence::compare(const DnaSequence &d) const {
    if(m_length_dna!= d.length())
        return false;
    for (unsigned int i = 0; i < m_length_dna; ++i) {
        if (m_dna_seq[i] != d[i])
            return false;
    }
    return true;
}
int DnaSequence::find(const DnaSequence d) const {
    size_t len1 = m_length_dna;
    size_t len2 = d.length();

    if(len2>len1){
        return -1;
    }
    for (unsigned int i = 0; i <(len1-len2+1) ; ++i) {
        unsigned int j;
        for ( j = 0; j < len2; ++j) {
            if (m_dna_seq[i+j]!=d[j])
                break;
        }
        if(j==len2){
            return i;
        }

    }
    return -1;
}
DnaSequence DnaSequence::slice(int start, int end) {
    std::string seq;
    for (int i = start; i < end; ++i) {
        seq.push_back(m_dna_seq[i].getChar());
    }
    return DnaSequence(seq);
}
DnaSequence  DnaSequence::pair() const {
    std::string seq;
    int j = 0;
    for (size_t i = m_length_dna; i >0; --i) {
        switch (m_dna_seq[i-1].getChar()){
            case 'C':seq.push_back('G');
                break;
            case 'G':seq.push_back('C');
                break;
            case 'T':seq.push_back('A');
                break;
            case 'A':seq.push_back('T');
                break;
        }
        j++;
    }
    return DnaSequence(seq);
}
std::vector<int> DnaSequence::findConsensusSequences() const {
    std::vector <int> first=findAll((char*)"ATG");
    std::vector<int> last1 =findAll((char*)"TAG");
    std::vector<int> last2 =findAll((char*)"TAA");
    std::vector<int> last3 =findAll((char*)"TGA");
    std::vector<int> merge1;
    std::vector<int> merge2;
    std::merge(last1.begin(),last1.end(),last2.begin(),last2.end(),merge1.begin());
    std::merge(last3.begin(),last3.end(),merge1.begin(),merge1.end(),merge2.begin());
    std::vector<int> indexes;
    for (unsigned int i = 0; i <first.size() ; ++i) {
        for (unsigned int j = 0; j < merge2.size(); ++j) {
            if(merge2[j]<first[i])
            {
                continue;
            }
            if((merge2[j]-first[i]+2)%3==0){
                indexes.push_back(first[i]);
            }
        }
    }
    return indexes;
}
void DnaSequence::output(IWriter* writer) const
{
   writer->write("ATGTGTGTGTGT");
}
