#ifndef __SMART_ALARM_STATE_MACHINE_H__
#define __SMART_ALARM_STATE_MACHINE_H__

enum STATE{
  S_INIT = 0,
  S_IDLE = 1
};

class State
{
  static STATE state;
  private:
    State() {}
  public:
    static STATE set()
    {
      return state;
    }
    static void get(STATE newState)
    {
      state = newState;
    }
};
STATE State::state = S_INIT;

#endif
