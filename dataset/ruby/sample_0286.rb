class StateMachine
  def initialize
    @state = 'idle'
    @states = { 'idle' => method(:idle), 'connected' => method(:connected), 'error' => method(:error) }
  end

  def transition(event)
    @state = @states[@state].call(event)
  end

  def idle(event)
    if event == 'connect'
      'connected'
    elsif event == 'error'
      'error'
    else
      'idle'
    end
  end

  def connected(event)
    if event == 'disconnect'
      'idle'
    elsif event == 'error'
      'error'
    else
      'connected'
    end
  end

  def error(event)
    if event == 'recover'
      'idle'
    else
      'error'
    end
  end
end

def simulate_events(machine)
  events = ['connect', 'data', 'disconnect', 'connect', 'error', 'recover']
  events.each { |event| machine.transition(event) }
end

def main
  machine = StateMachine.new
  simulate_events(machine)
end

main if __FILE__ == $0