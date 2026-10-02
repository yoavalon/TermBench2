class NetworkState
  def initialize
    @state = 'init'
  end

  def transition(event)
    if @state == 'init' && event == 'connect'
      @state = 'connected'
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'disconnected'
    elsif @state == 'disconnected' && event == 'reconnect'
      @state = 'connected'
    end
  end
end

class EventProcessor
  def initialize(state_machine)
    @state_machine = state_machine
    @events = []
  end

  def add_event(event)
    @events << event
  end

  def process_events
    @events.each do |event|
      @state_machine.transition(event)
    end
    @events.clear
  end
end

def main
  state_machine = NetworkState.new
  processor = EventProcessor.new(state_machine)
  processor.add_event('connect')
  processor.process_events
  processor.add_event('disconnect')
  processor.process_events
  processor.add_event('reconnect')
  processor.process_events
  puts state_machine.state
end

main if __FILE__ == $0