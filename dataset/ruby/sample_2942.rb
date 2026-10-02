class NetworkState
  def initialize
    @state = 'idle'
  end

  def transition(event)
    case @state
    when 'idle'
      @state = 'connected' if event == 'connect'
      @state = 'error' if event == 'error'
    when 'connected'
      @state = 'idle' if event == 'disconnect'
      @state = 'error' if event == 'error'
    when 'error'
      @state = 'idle' if event == 'recover'
    end
  end
end

class EventGenerator
  def initialize
    @event_sequence = ['connect', 'data', 'disconnect', 'connect', 'data', 'error', 'recover']
  end

  def next_event
    @event_sequence.shift unless @event_sequence.empty?
  end
end

class NetworkSystem
  def initialize
    @state_machine = NetworkState.new
    @event_generator = EventGenerator.new
  end

  def process_events
    loop do
      event = @event_generator.next_event
      if event
        @state_machine.transition(event)
        handle_error if @state_machine.state == 'error'
      end
    end
  end

  def handle_error
    puts 'Error state reached, attempting recovery...'
    @state_machine.transition('recover')
  end
end

def main
  network_system = NetworkSystem.new
  network_system.process_events
end

main