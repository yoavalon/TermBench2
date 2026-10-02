class StateMachine

  def initialize(states)
    @states = states
    @current_state = states[0]
  end

  def transition(event)
    new_state = @current_state.next_state(event)
    if @states.include?(new_state)
      @current_state = new_state
    end
    @current_state
  end

end

class State

  def initialize(name, next_state_map)
    @name = name
    @next_state_map = next_state_map
  end

  def next_state(event)
    @next_state_map[event] || self
  end

end

class EventGenerator

  def initialize(events)
    @events = events
    @index = 0
  end

  def next_event
    event = @events[@index % @events.length]
    @index += 1
    event
  end

end

def main
  state1 = State.new('CONNECTING', {'OK' => State.new('CONNECTED', {}), 'FAIL' => State.new('DISCONNECTED', {})})
  state2 = State.new('CONNECTED', {'LOSE' => State.new('DISCONNECTED', {}), 'KEEP' => state1})
  state3 = State.new('DISCONNECTED', {'RETRY' => state1})
  states = [state1, state2, state3]
  sm = StateMachine.new(states)
  events = ['OK', 'LOSE', 'RETRY', 'KEEP', 'FAIL']
  eg = EventGenerator.new(events)
  while true
    event = eg.next_event
    sm.transition(event)
  end
end

main