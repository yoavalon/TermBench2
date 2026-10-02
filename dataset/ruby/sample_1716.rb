class NetworkState
  def initialize
    @state = 'DISCONNECTED'
  end

  def transition(event)
    if @state == 'DISCONNECTED' && event == 'CONNECT'
      @state = 'CONNECTED'
    elsif @state == 'CONNECTED' && event == 'DATA_RECEIVED'
      @state = 'DATA_PROCESSING'
    elsif @state == 'DATA_PROCESSING' && event == 'DATA_PROCESSED'
      @state = 'CONNECTED'
    elsif @state == 'CONNECTED' && event == 'DISCONNECT'
      @state = 'DISCONNECTED'
    end
  end
end

class NetworkEventGenerator
  def initialize
    @events = ['CONNECT', 'DATA_RECEIVED', 'DATA_PROCESSED', 'DISCONNECT']
    @index = 0
  end

  def next_event
    event = @events[@index]
    @index = (@index + 1) % @events.length
    event
  end
end

class NetworkSystem
  def initialize
    @state_machine = NetworkState.new
    @event_generator = NetworkEventGenerator.new
  end

  def run
    loop do
      event = @event_generator.next_event
      @state_machine.transition(event)
    end
  end
end

def main
  system = NetworkSystem.new
  system.run
end

main