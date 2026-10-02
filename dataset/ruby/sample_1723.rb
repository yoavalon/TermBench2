class StateMachine
  def initialize
    @state = 'idle'
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'connected'
    elsif @state == 'connected' && event == 'data'
      @state = 'transmitting'
    elsif @state == 'transmitting' && event == 'disconnect'
      @state = 'disconnected'
    elsif @state == 'disconnected' && event == 'reset'
      @state = 'idle'
    end
  end

  def handle_event(event)
    transition(event)
    @state
  end
end

class EventGenerator
  def initialize
    @events = ['connect', 'data', 'disconnect', 'reset']
    @index = 0
  end

  def next_event
    event = @events[@index % @events.length]
    @index += 1
    event
  end
end

class NetworkSystem
  def initialize
    @state_machine = StateMachine.new
    @event_generator = EventGenerator.new
  end

  def run
    loop do
      event = @event_generator.next_event
      state = @state_machine.handle_event(event)
      puts "Event: #{event}, State: #{state}"
    end
  end
end

def main
  network_system = NetworkSystem.new
  network_system.run
end

main