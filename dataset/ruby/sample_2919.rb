class NetworkState
  def initialize
    @state = 'idle'
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'active'
    elsif @state == 'active' && event == 'disconnect'
      @state = 'idle'
    elsif @state == 'active' && event == 'data'
      @state = 'processing'
    elsif @state == 'processing' && event == 'complete'
      @state = 'active'
    elsif @state == 'processing' && event == 'error'
      @state = 'active'
    end
    @state
  end
end

class EventGenerator
  def initialize
    @events = ['connect', 'data', 'complete', 'error', 'disconnect']
    @index = 0
  end

  def get_event
    event = @events[@index]
    @index = (@index + 1) % @events.length
    event
  end
end

class NetworkSystem
  def initialize
    @state_machine = NetworkState.new
    @event_generator = EventGenerator.new
  end

  def run
    loop do
      event = @event_generator.get_event
      new_state = @state_machine.transition(event)
      puts "Event: #{event}, New State: #{new_state}"
    end
  end
end

def main
  network_system = NetworkSystem.new
  network_system.run
end

main