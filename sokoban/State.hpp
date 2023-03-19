#ifndef STATE_HPP
#define STATE_HPP

  class State {
    public:
      State();
      virtual void update() = 0;
      virtual ~State();
  };

#endif