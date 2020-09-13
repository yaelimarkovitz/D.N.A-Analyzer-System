#include <exception>
#include <iostream>
class InVailidNeculeotide:public std::exception{
    virtual const char* what() const throw();
};
inline const char* InVailidNeculeotide::what() const throw(){
    return "sorry but you enter in valid necukeotide";
}
class TooLargIndex:public std::exception{
    virtual const char* what() const throw();
};
inline const char* TooLargIndex::what() const throw(){
    return "sorry but the index is out of range";
}