#ifndef __ADAPTER_PATTERN_H__
#define __ADAPTER_PATTERN_H__

using Cable = int;

class EuSocketInterface {
public:
    virtual int   voltage() = 0;
    virtual Cable live()    = 0;
    virtual Cable nutral()  = 0;
    virtual Cable earth()   = 0;
};

class EuSocket : public EuSocketInterface {
public:
    int   voltage() override { return 240; }
    Cable live() override { return 1; }
    Cable nutral() override { return -1; }
    Cable earth() override { return 0; }
};

class UsSocketInterface {
public:
    virtual int   voltage() = 0;
    virtual Cable live()    = 0;
    virtual Cable nutral()  = 0;
};

class UsSocketAdapter : public UsSocketInterface {
public:
    void  plugin(EuSocketInterface *euSocket) { m_euSocket = euSocket; }
    int   voltage() override { return 110; }
    Cable live() override { return m_euSocket->live(); }
    Cable nutral() override { return m_euSocket->nutral(); }

private:
    EuSocketInterface *m_euSocket{nullptr};
};

// Client
class ElectricKettle {
public:
    void plugin(UsSocketInterface *supply) { m_power = supply; }

    int boil() {
        if (m_power->voltage() > 110) {  // power not supported
            return -1;
        }

        if (m_power->live() == 1 && m_power->nutral() == -1) {
            return 0;
        }
        return -1;
    }

private:
    UsSocketInterface *m_power{nullptr};
};

#endif
