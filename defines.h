#ifndef DEFINES_H
#define DEFINES_H

#include "main.h"

    template <class T> 
char *to_string(T an_int)
{
    std::ostringstream sout;
    sout << an_int;

    char *buff = new char[sout.str().length()+1];
    std::strcpy(buff,sout.str().c_str());
    return buff;
};

#endif
