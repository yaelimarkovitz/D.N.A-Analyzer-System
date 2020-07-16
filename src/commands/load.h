//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_LOAD_H
#define UNTITLED_LOAD_H

#include "../ICommand.h"
#include "../dna_data_base.h"
#include "../dna_info.h"

class Load : public ICommand {
public:
    ~Load();
    std::string execute(std::vector<std::string> params);
private:
    DnaInfo* m_seq;
    std::string fileName;
    std::string generateName(const std::string& fileName);
    std::string itoa(int num);
};

inline Load::~Load() {
    delete m_seq;
}

inline std::string Load::execute(std::vector<std::string> params) {
    size_t numOfParams = params.size();
    std::string tmp = "GTGT";
    if(numOfParams>3 || numOfParams<2){
        return "no valid input";
    }
    if(m_seq!=NULL){
        delete m_seq;
    }
    if(params.size()==3){
        m_seq = new DnaInfo(tmp,params[2].substr(1,params[2].size()-1));
    }
    else{
        std::string name = generateName(params[1]);
        m_seq = new DnaInfo(tmp,name);
    }
    return m_seq->getInfo();
}

inline std::string Load::generateName(const std::string& fileName) {
    static size_t number = 0;
    number++;
    return (fileName.substr(0,fileName.find("."))+itoa(number));
}

inline std::string Load::itoa(int num) {
    std::string ss = "";
    while(num){
        int x = num % 10;
        num /= 10;
        char i = '0';
        i = i + x ;
        ss = i + ss;
    }
    return ss;
}
#endif //UNTITLED_LOAD_H
