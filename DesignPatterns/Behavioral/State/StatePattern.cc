#include "StatePattern.h"

#include <iostream>

Session::Session() : m_state(&InitState::getInstance()) {}
void    Session::init() { m_state->init(*this); }
void    Session::configured() { m_state->configured(*this); }
void    Session::active() { m_state->active(*this); }
void    Session::terminating() { m_state->terminating(*this); }
void    Session::terminated() { m_state->terminated(*this); }
StateId Session::getStateId() { return m_state->getId(); }

// State class implementation
void State::init(Session& session) { std::cout << "Not Supported\n"; }
void State::configured(Session& session) { std::cout << "Not Supported\n"; }
void State::active(Session& session) { std::cout << "Not Supported\n"; }
void State::terminating(Session& session) { std::cout << "Not Supported\n"; }
void State::terminated(Session& session) { std::cout << "Not Supported\n"; }

// InitState class implementation
void InitState::configured(Session& session) {
    std::cout << "Performing Init to Configured Processing\n";
    // Change state to configured
    changeState(session, ConfiguredState::getInstance());
}

void InitState::terminating(Session& session) {
    std::cout << "Performing Init to Terminating Processing\n";
    // Change state to configured
    changeState(session, TerminatingState::getInstance());
}

void InitState::terminated(Session& session) {
    std::cout << "Performing Init to Terminated Processing\n";
    // Change state to configured
    changeState(session, TerminatedState::getInstance());
}

// ConfiguredState class implementation
void ConfiguredState::active(Session& session) {
    std::cout << "Performing Configured to Active Processing\n";
    // Change state to configured
    changeState(session, ActiveState::getInstance());
}

void ConfiguredState::terminating(Session& session) {
    std::cout << "Performing Configured to Terminating Processing\n";
    // Change state to configured
    changeState(session, TerminatingState::getInstance());
}

void ConfiguredState::terminated(Session& session) {
    std::cout << "Performing Configured to Terminated Processing\n";
    // Change state to configured
    changeState(session, TerminatedState::getInstance());
}

// ActiveState class implementation
void ActiveState::terminating(Session& session) {
    std::cout << "Performing Active to Terminating Processing\n";
    // Change state to configured
    changeState(session, TerminatingState::getInstance());
}

void ActiveState::terminated(Session& session) {
    std::cout << "Performing Active to Terminated Processing\n";
    // Change state to configured
    changeState(session, TerminatedState::getInstance());
}

// TerminatingState class implementation
void TerminatingState::terminated(Session& session) {
    std::cout << "Performing Terminating to Terminated Processing\n";
    // Change state to configured
    changeState(session, TerminatedState::getInstance());
}
