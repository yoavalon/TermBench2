class ConnectionState
  def initialize
    @state = 'DISCONNECTED'
    @states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING']
  end

  def transition(event)
    if @state == 'DISCONNECTED' && event == 'CONNECT'
      @state = 'CONNECTING'
    elsif @state == 'CONNECTING'
      @state = 'CONNECTED'
    elsif @state == 'CONNECTED' && event == 'DISCONNECT'
      @state = 'DISCONNECTING'
    elsif @state == 'DISCONNECTING'
      @state = 'DISCONNECTED'
    end
  end

  def current_state
    @state
  end
end

class EventGenerator
  def initialize
    @events = ['CONNECT', 'DISCONNECT']
    @index = 0
  end

  def next_event
    event = @events[@index]
    @index = (@index + 1) % @events.length
    event
  end
end

class NetworkSimulator
  def initialize
    @state_machine = ConnectionState.new
    @event_generator = EventGenerator.new
  end

  def simulate
    loop do
      event = @event_generator.next_event
      @state_machine.transition(event)
      puts @state_machine.current_state
    end
  end
end

def main
  simulator = NetworkSimulator.new
  simulator.simulate
end

main