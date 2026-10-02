class ConnectionState
  def initialize
    @state = 'idle'
    @connection_id = 0
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'established'
      @connection_id += 1
    elsif @state == 'established' && event == 'disconnect'
      @state = 'idle'
    elsif @state == 'established' && event == 'data'
      @state = 'transmitting'
    elsif @state == 'transmitting' && event == 'complete'
      @state = 'established'
    end
    @state
  end
end

class NetworkSimulator
  def initialize
    @connection = ConnectionState.new
  end

  def process_event(event)
    new_state = @connection.transition(event)
    new_state
  end
end

class EventGenerator
  def initialize
    @events = ['connect', 'data', 'complete', 'disconnect']
    @index = 0
  end

  def generate
    event = @events[@index % @events.length]
    @index += 1
    event
  end
end

def main
  simulator = NetworkSimulator.new
  generator = EventGenerator.new
  loop do
    event = generator.generate
    new_state = simulator.process_event(event)
    puts "Event: #{event}, New State: #{new_state}"
  end
end

main