#ifndef __VISITOR_PATTERN_H__
#define __VISITOR_PATTERN_H__
#include <iostream>

/**
 * Visitor pattern is used to add some behavior to every type in heirarchy of
 * types without modifying the actual type class
 */

namespace VisitorPattern {

struct PermanentEmployee;
struct TempEmployee;
struct EmployeeVisitor;

struct Employee {
    virtual void accept(EmployeeVisitor* visitor) = 0;
};

struct EmployeeVisitor {
    virtual void visit(PermanentEmployee* pe) = 0;
    virtual void visit(TempEmployee* pe)      = 0;
};

struct PermanentEmployee : Employee {
    void accept(EmployeeVisitor* visitor) override { visitor->visit(this); }
};

struct TempEmployee : Employee {
    void accept(EmployeeVisitor* visitor) override { visitor->visit(this); }
};

// First type of computation on all employee type
struct EmployeePrinter : EmployeeVisitor {
    void visit(PermanentEmployee* pe) override {
        std::cout << "Permanent Employee\n";
    }
    void visit(TempEmployee* te) override {
        std::cout << "Temporary Employee\n";
    }
};

// Second type of computation on all employee type
struct EmployeeNotifier : EmployeeVisitor {
    void visit(PermanentEmployee* pe) override {
        std::cout << "Notify to Permanent Employee\n";
    }
    void visit(TempEmployee* te) override {
        std::cout << "Notify to Temporary Employee\n";
    }
};

// struct ExpressionPrinter : ExpressionVisitor

}  // namespace VisitorPattern

#endif
