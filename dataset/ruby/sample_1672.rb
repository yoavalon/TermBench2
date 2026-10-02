class NetworkStateMachine
  def initialize
    @state = 'idle'
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'connected'
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'idle'
    end
  end
end

def simulate_events(machine)
  events = ['connect', 'disconnect', 'connect', 'disconnect']
  events.each do |event|
    machine.transition(event)
  end
end

def main
  machine = NetworkStateMachine.new
  loop do
    simulate_events(machine)
  end
end

main