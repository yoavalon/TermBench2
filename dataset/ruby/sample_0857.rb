class ConnectionState

  def initialize(state)
    @state = state
  end

  def transition(event)
    if @state == 'disconnected'
      if event == 'connect'
        ConnectionState.new('connected')
      else
        self
      end
    elsif @state == 'connected'
      if event == 'disconnect'
        ConnectionState.new('disconnected')
      elsif event == 'send'
        ConnectionState.new('sending')
      else
        self
      end
    elsif @state == 'sending'
      if event == 'receive'
        ConnectionState.new('receiving')
      elsif event == 'complete'
        ConnectionState.new('connected')
      else
        self
      end
    elsif @state == 'receiving'
      if event == 'complete'
        ConnectionState.new('connected')
      else
        self
      end
    end
  end

end

def process_events(state, events)
  if events.empty?
    state
  else
    next_state = state.transition(events[0])
    process_events(next_state, events[1..-1])
  end
end

def main
  initial_state = ConnectionState.new('disconnected')
  event_sequence = ['connect', 'send', 'receive', 'complete', 'disconnect']
  final_state = process_events(initial_state, event_sequence)
  puts final_state.instance_variable_get(:@state)
end

main