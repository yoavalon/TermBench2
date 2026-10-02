class NetworkState

  def initialize
    @state = 'idle'
    @connection = nil
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'connected'
      @connection = true
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'idle'
      @connection = false
    elsif @state == 'idle' && event == 'error'
      @state = 'error'
    elsif @state == 'connected' && event == 'error'
      @state = 'error'
    elsif @state == 'error' && event == 'recover'
      @state = 'idle'
    end
  end
end

class EventGenerator

  def initialize
    @events = ['connect', 'disconnect', 'error', 'recover']
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
    @event_source = EventGenerator.new
  end

  def run
    loop do
      event = @event_source.next_event
      @state_machine.transition(event)
      puts "Event: #{event}, State: #{@state_machine.state}"
    end
  end
end

def main
  system = NetworkSystem.new
  system.run
end

main