#ifndef __STATE_PATTERN_H__
#define __STATE_PATTERN_H__
#include <iostream>

#include "Singleton.h"

class State;

enum class StateId { Init, Configured, Active, Terminating, Terminated };
// Session for which state is required
class Session {
public:
    Session();
    void init();
    void configured();
    void active();
    void terminating();
    void terminated();

    StateId getStateId();

private:
    friend class State;
    void   setState(State& state) { m_state = &state; }
    State* m_state;
};

// Base State class implementing default state behaviour
class State {
public:
    virtual void init(Session& session);
    virtual void configured(Session& session);
    virtual void active(Session& session);
    virtual void terminating(Session& session);
    virtual void terminated(Session& session);

    virtual StateId getId() = 0;

protected:
    void changeState(Session& session, State& state) {
        session.setState(state);
    }
};

// Singleton Concrete Init State
class InitState : public State, public Singleton<InitState> {
public:
    void configured(Session& session);
    void terminating(Session& session);
    void terminated(Session& session);

    StateId getId() { return StateId::Init; }

private:
    friend SingletonDerive;
    InitState() = default;
};

// Singleton Concrete Configured State
class ConfiguredState : public State, public Singleton<ConfiguredState> {
public:
    void active(Session& session);
    void terminating(Session& session);
    void terminated(Session& session);

    StateId getId() { return StateId::Configured; }

private:
    friend SingletonDerive;
    ConfiguredState() = default;
};

// Singleton Concrete Active State
class ActiveState : public State, public Singleton<ActiveState> {
public:
    void terminating(Session& session);
    void terminated(Session& session);

    StateId getId() { return StateId::Active; }

private:
    friend SingletonDerive;
    ActiveState() = default;
};

// Singleton Concrete Terminating State
class TerminatingState : public State, public Singleton<TerminatingState> {
public:
    void terminated(Session& session);

    StateId getId() { return StateId::Terminating; }

private:
    friend SingletonDerive;
    TerminatingState() = default;
};

// Singleton Concrete Terminated State
class TerminatedState : public State, public Singleton<TerminatedState> {
public:
    StateId getId() { return StateId::Terminated; }

private:
    friend SingletonDerive;
    TerminatedState() = default;
};

#endif
