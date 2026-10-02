class NetworkStateMachine

  def initialize(states, transitions)
    @states = states
    @transitions = transitions
    @current_state = states[0]
  end

  def transition(event)
    if @transitions.key?([@current_state, event])
      @current_state = @transitions[[@current_state, event]]
    else
      raise ValueError, 'Invalid transition'
    end
  end

  def is_terminal
    ['disconnected', 'error'].include?(@current_state)
  end
end

class EventManager

  def initialize(events)
    @events = events
    @index = 0
  end

  def get_next_event
    if @index < @events.length
      event = @events[@index]
      @index += 1
      event
    else
      nil
    end
  end
end

def main
  states = ['idle', 'connected', 'disconnected', 'error']
  transitions = {['idle', 'connect'] => 'connected', ['connected', 'disconnect'] => 'disconnected', ['connected', 'error'] => 'error', ['disconnected', 'connect'] => 'connected', ['error', 'reset'] => 'idle'}
  events = ['connect', 'disconnect', 'error', 'reset', 'connect', 'disconnect', 'connect', 'error', 'reset']
  network_machine = NetworkStateMachine.new(states, transitions)
  event_manager = EventManager.new(events)
  while true
    event = event_manager.get_next_event
    break if event.nil? || network_machine.is_terminal
    network_machine.transition(event)
  end
  puts "Final state: #{network_machine.current_state}"
end

main if __FILE__ == $0