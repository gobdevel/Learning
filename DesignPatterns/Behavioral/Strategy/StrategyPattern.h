#ifndef __STRATEGY_PATTERN_H__
#define __STRATEGY_PATTERN_H__

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

// Template - 1 Dynamic strategy

class PrinterStrategy {
public:
    virtual void start() {}
    virtual void print(std::string& str) {}
    virtual void end() {}
};

class SmallLetterStrategy : public PrinterStrategy {
public:
    void start() override { std::cout << __PRETTY_FUNCTION__ << " => Start\n"; }
    void end() override { std::cout << __PRETTY_FUNCTION__ << " => End\n"; }
    void print(std::string& str) override {
        std::transform(str.begin(), str.end(), str.begin(),
                       [](auto c) { return std::tolower(c); });
        std::cout << str;
    }
};

class CapitalLetterStrategy : public PrinterStrategy {
public:
    void start() override { std::cout << __PRETTY_FUNCTION__ << " => Start\n"; }
    void end() override { std::cout << __PRETTY_FUNCTION__ << " => End\n"; }
    void print(std::string& str) override {
        std::transform(str.begin(), str.end(), str.begin(),
                       [](auto c) { return std::toupper(c); });
        std::cout << str;
    }
};

class Printer {
public:
    Printer(PrinterStrategy& strategy) : m_strategy(strategy) {}
    void print(std::string& str) {
        m_strategy.start();
        m_strategy.print(str);
        std::cout << "\n";
        m_strategy.end();
    }

private:
    PrinterStrategy& m_strategy;
};

// Template - 2 Static Strategy

template <typename Strategy>
class StaticPrinter {
public:
    void print(std::string& str) {
        m_strategy.start();
        m_strategy.print(str);
        std::cout << "\n";
        m_strategy.end();
    }

private:
    Strategy m_strategy;
};

#endif
