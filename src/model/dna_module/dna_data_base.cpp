//
// Created by mby on 14/07/2020.
//

#include "dna_data_base.h"

std::map<std::string, DnaInfo*> DnaDataBase:: dnaList= createMap();
std::map<size_t,std::string> DnaDataBase::idList = createMapn();