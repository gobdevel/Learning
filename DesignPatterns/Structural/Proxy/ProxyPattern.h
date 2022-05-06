#ifndef __PROXY_PATTERN_H__
#define __PROXY_PATTERN_H__

// Smart pointer proxy

#include <memory>
#include <string>

struct BankAccount {
    void deposit(int amount) {}
};

static void illustrationSmartPointerProxy() {
    BankAccount *ba = new BankAccount();
    ba->deposit(100);

    auto bap = std::make_shared<BankAccount>();
    bap->deposit(100);  // same as above
}

// Property Proxy
template <typename T>
struct Property {
    T value;
    Property(const T initialValue) {
        *this = initialValue;  // invoke operator=
    }
    operator T() { return value; }

    T operator=(T newValue) { return value = newValue; }
};

struct Creature {
    Property<int> strength{10};
    Property<int> agility{3};
};

static void propertyProxyExample() {
    Creature creature;
    creature.agility = 20;                 // setter
    auto val         = creature.strength;  // getter
}

// Virtual Proxy

struct Image {
    virtual void draw() = 0;
};

struct Bitmap : public Image {
    Bitmap(std::string filename) {}
    void draw() override {
        //
    }
};

struct LazyBitmap : public Image {
    LazyBitmap(std::string filename) {}
    void draw() override {
        if (!bp) {
            bp = new Bitmap(filename);
        }
        bp->draw();
    }

private:
    Bitmap     *bp{nullptr};
    std::string filename;
};

// Communication Proxy

struct Pingable {
    virtual std::string ping(const std::string &msg) = 0;
};

struct Pong : public Pingable {
    std::string ping(const std::string &msg) { return (msg + " pong"); }
};

struct RemotePong : public Pingable {
    std::string ping(const std::string &msg) {
        // REST Client send msg to remote
        // Wait for reply
        return (msg + " reply from remote");
    }
};

#endif
