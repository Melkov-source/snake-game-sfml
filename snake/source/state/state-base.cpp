#include "../../include/state/state-base.h"

namespace state
{
    StateBase::StateBase(sf::RenderWindow* render_window) :
        state_code(STATE_ENTER_CODE), render_window_(render_window)
    {
    }

    StateBase::~StateBase()
    {
    }

    void StateBase::update(const float delta_time)
    {
    }

    void StateBase::exit()
    {
        this->state_code = STATE_EXIT_CODE;
    }
}
