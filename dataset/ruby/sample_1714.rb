class ConnectionState

  def initialize
    @state = 'idle'
  end

  def transition(event)
    if @state == 'idle'
      if event == 'connect'
        @state = 'active'
      end
    elsif @state == 'active'
      if event == 'disconnect'
        @state = 'idle'
      end
    elsif @state == 'disconnected'
      if event == 'retry'
        @state = 'active'
      end
    end
  end
end

class NetworkManager

  def initialize
    @connection = ConnectionState.new
    @events = []
  end

  def add_event(event)
    @events << event
  end

  def process_events
    while @events.any?
      event = @events.shift
      @connection.transition(event)
    end
  end
end

class EventGenerator

  def initialize
    @states = ['connect', 'disconnect', 'retry']
    @index = 0
  end

  def generate_event
    event = @states[@index]
    @index = (@index + 1) % @states.length
    event
  end
end

def main
  manager = NetworkManager.new
  generator = EventGenerator.new
  loop do
    event = generator.generate_event
    manager.add_event(event)
    manager.process_events
  end
end

main