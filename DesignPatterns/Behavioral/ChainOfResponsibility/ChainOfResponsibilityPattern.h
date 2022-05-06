#ifndef __CHAIN_OF_RESPONSIBILITY_PATTERN_H__
#define __CHAIN_OF_RESPONSIBILITY_PATTERN_H__

enum class Operation { add, sub, mult, div, pow };

struct Numbers {
    int a, b;
    Numbers(int x, int y) : a(x), b(y) {}
};

class Chain {
public:
    virtual int  process(const Numbers& nums, Operation op) = 0;
    virtual void addNextInChain(Chain* next) { m_next = next; }

protected:
    Chain* m_next{nullptr};
};

class AdditionChain : public Chain {
public:
    int process(const Numbers& nums, Operation op) override {
        return (op == Operation::add ? (nums.a + nums.b)
                                     : m_next->process(nums, op));
    }
};

class SubtractionChain : public Chain {
public:
    int process(const Numbers& nums, Operation op) override {
        return (op == Operation::sub ? (nums.a - nums.b)
                                     : m_next->process(nums, op));
    }
};

class MultiplicationChain : public Chain {
public:
    int process(const Numbers& nums, Operation op) override {
        return (op == Operation::mult ? (nums.a * nums.b)
                                      : m_next->process(nums, op));
    }
};

class DivisionChain : public Chain {
public:
    int process(const Numbers& nums, Operation op) override {
        return (op == Operation::div ? (nums.a / nums.b) : -1);
    }
};

#endif
