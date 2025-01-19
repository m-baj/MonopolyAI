//
// Created by adrwal on 1/19/25.
//


#ifndef FIELDVISITOR_H
#define FIELDVISITOR_H
#include <vector>

class OwnableField;
class TaxField;
class GoToJailField;
class Field;
class CardField;
class Utilities;
class Property;
class Trains;

class FieldVisitor {
public:
    virtual ~FieldVisitor() = default;
    virtual void visitTrains(Trains& field) {};
    virtual void visitProperty(Property& field) {};
    virtual void visitUtilities(Utilities& field) {};
    virtual void visitCardField(CardField& field) {};
    virtual void visitField(Field& field) {};
    virtual void visitGoToJailField(GoToJailField& field) {};
    virtual void visitTaxField(TaxField& field) {};
    virtual void visitOwnableField(OwnableField& field) {};
};



#endif //FIELDVISITOR_H
