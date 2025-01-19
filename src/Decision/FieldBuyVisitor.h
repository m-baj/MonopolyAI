//
// Created by adrwal on 1/19/25.
//

#ifndef FIELDBUYVISITOR_H
#define FIELDBUYVISITOR_H
#include "FieldVisitor.h"


class FieldBuyVisitor final : public FieldVisitor {
public:
    FieldBuyVisitor() = default;
    void visitProperty(Property& field) override;
};



#endif //FIELDBUYVISITOR_H
