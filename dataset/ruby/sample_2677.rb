class StateMachine
  attr_accessor :states, :transitions, :current_state, :sequence

  def initialize(states, transitions, start_state)
    @states = states
    @transitions = transitions
    @current_state = start_state
    @sequence = []
  end

  def transition(event)
    if @transitions.key?([@current_state, event])
      next_state = @transitions[[@current_state, event]]
      @current_state = next_state
      @sequence << event
    else
      raise ArgumentError, 'Invalid transition'
    end
  end

  def is_terminated
    @states['terminal'].include?(@current_state)
  end
end

class NetworkConnection
  def initialize(state_machine)
    @state_machine = state_machine
  end

  def process_events(events)
    events.each do |event|
      @state_machine.transition(event)
      break if @state_machine.is_terminated
    end
  end
end

def main
  states = {'initial' => ['connected', 'disconnected'], 'connected' => ['sending', 'receiving', 'disconnected'], 'sending' => ['connected', 'disconnected'], 'receiving' => ['connected', 'disconnected'], 'terminal' => ['disconnected']}
  transitions = {['initial', 'connect'] => 'connected', ['connected', 'send'] => 'sending', ['connected', 'receive'] => 'receiving', ['connected', 'disconnect'] => 'disconnected', ['sending', 'connect'] => 'connected', ['sending', 'disconnect'] => 'disconnected', ['receiving', 'connect'] => 'connected', ['receiving', 'disconnect'] => 'disconnected'}
  start_state = 'initial'
  state_machine = StateMachine.new(states, transitions, start_state)
  network_connection = NetworkConnection.new(state_machine)
  events = ['connect', 'send', 'receive', 'disconnect']
  network_connection.process_events(events)
  puts 'Sequence:', state_machine.sequence
  puts 'Terminated:', state_machine.is_terminated
end

main if __FILE__ == $0