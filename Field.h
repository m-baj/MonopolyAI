//
// Created by adrwal on 11/3/24.
//

#ifndef FIELD_H
#define FIELD_H
#include <string>


class Field {
public:
    virtual ~Field() = default;
    virtual void onPlayerEnter() = 0;

private:
    std::string name;
};



#endif //FIELD_H
