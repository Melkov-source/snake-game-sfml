#include "../../include/states/state-base.h"

StateBase::StateBase(sf::RenderWindow* render_window) :
    state_code(state::STATE_ENTER_CODE), render_window_(render_window)
{
}

StateBase::~StateBase()
{
    std::cout << "state.delete: " << this << "\n";
}

void StateBase::exit()
{
    this->state_code = state::STATE_EXIT_CODE;
}
