class NetworkState
  def initialize(state)
    @state = state
  end

  def transition(event)
    if @state == 'DISCONNECTED' && event == 'CONNECT'
      'CONNECTED'
    elsif @state == 'CONNECTED' && event == 'DISCONNECT'
      'DISCONNECTED'
    elsif @state == 'CONNECTED' && event == 'RECEIVE'
      'PROCESSING'
    elsif @state == 'PROCESSING' && event == 'SEND'
      'CONNECTED'
    else
      @state
    end
  end
end

class NetworkStateMachine
  def initialize
    @current_state = NetworkState.new('DISCONNECTED')
  end

  def process_event(event)
    new_state = @current_state.transition(event)
    @current_state = NetworkState.new(new_state)
    new_state
  end
end

def generate_events
  events = ['CONNECT', 'RECEIVE', 'SEND', 'DISCONNECT']
  events * 10
end

def simulate_network
  state_machine = NetworkStateMachine.new
  events = generate_events
  index = 0
  while true
    event = events[index % events.length]
    new_state = state_machine.process_event(event)
    index += 1
    if new_state == 'PROCESSING'
      simulate_network
    end
  end
end

def main
  simulate_network
end

main