class State
  def initialize(name)
    @name = name
  end

  def transition(event, states)
  end
end

class OpenState < State
  def transition(event, states)
    if event == 'close'
      states['closed']
    elsif event == 'error'
      states['error']
    else
      self
    end
  end
end

class ClosedState < State
  def transition(event, states)
    if event == 'open'
      states['open']
    else
      self
    end
  end
end

class ErrorState < State
  def transition(event, states)
    if event == 'recover'
      states['open']
    else
      self
    end
  end
end

def process_events(current_state, events, states)
  return current_state if events.empty?
  next_state = current_state.transition(events[0], states)
  process_events(next_state, events[1..-1], states)
end

def main
  open_state = OpenState.new('open')
  closed_state = ClosedState.new('closed')
  error_state = ErrorState.new('error')
  states = { 'open' => open_state, 'closed' => closed_state, 'error' => error_state }
  current_state = states['closed']
  event_sequence = ['open', 'data', 'data', 'close', 'open', 'error', 'recover', 'close']
  final_state = process_events(current_state, event_sequence, states)
  puts final_state.name
end

main if __FILE__ == $0