#include "../../include/state/state-base.h"

state::StateBase::StateBase(sf::RenderWindow* render_window) :
    state_code(STATE_ENTER_CODE), render_window_(render_window)
{
}

state::StateBase::~StateBase()
{
}

void state::StateBase::update(const float delta_time)
{
}

void state::StateBase::exit()
{
    this->state_code = STATE_EXIT_CODE;
}
