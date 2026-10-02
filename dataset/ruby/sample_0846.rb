class StateMachine

  def initialize(state)
    @state = state
  end

  def transition(event)
    if @state == 'idle'
      if event == 'connect'
        @state = 'connected'
      elsif event == 'disconnect'
        @state = 'disconnected'
      end
    elsif @state == 'connected'
      if event == 'data'
        @state = 'data_received'
      elsif event == 'disconnect'
        @state = 'disconnected'
      end
    elsif @state == 'data_received'
      if event == 'ack'
        @state = 'idle'
      elsif event == 'disconnect'
        @state = 'disconnected'
      end
    elsif @state == 'disconnected'
      if event == 'connect'
        @state = 'connected'
      end
    end
  end

  def get_state
    @state
  end

end

def simulate_network_events(sm, events)
  events.each do |event|
    sm.transition(event)
  end
end

def check_termination(sm, target_state, max_steps)
  steps = 0
  while sm.get_state != target_state && steps < max_steps
    sm.transition('data')
    steps += 1
  end
  sm.get_state == target_state
end

def main
  sm = StateMachine.new('idle')
  events = ['connect', 'data', 'ack', 'disconnect']
  simulate_network_events(sm, events)
  terminated = check_termination(sm, 'idle', 10)
  puts terminated
end

main