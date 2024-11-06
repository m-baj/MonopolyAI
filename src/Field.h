//
// Created by adrwal on 11/3/24.
//

#ifndef FIELD_H
#define FIELD_H
#include <string>


class Field {
public:
    explicit Field(std::string name);
    virtual ~Field() = default;
    virtual void onPlayerEnter() = 0;

protected:
    std::string name;
};



#endif //FIELD_H
