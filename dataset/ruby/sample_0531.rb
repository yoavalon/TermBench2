class State
  def transition(event)
    self
  end
end

class ClosedState < State
  def transition(event)
    if event == 'open'
      OpenState.new
    else
      self
    end
  end
end

class OpenState < State
  def transition(event)
    if event == 'close'
      ClosedState.new
    elsif event == 'data'
      DataState.new
    else
      self
    end
  end
end

class DataState < State
  def transition(event)
    if event == 'close'
      ClosedState.new
    elsif event == 'data'
      self
    else
      OpenState.new
    end
  end
end

def event_generator
  states = ['open', 'data', 'close']
  loop do
    yield states[0]
    states = states[1..-1] + states[0..0]
  end
end

def state_machine
  current_state = ClosedState.new
  event_generator.each do |event|
    current_state = current_state.transition(event)
  end
end

def main
  state_machine
end

main