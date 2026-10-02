class NetworkStateMachine
  def initialize
    @state = 'disconnected'
    @events = []
  end

  def transition(event)
    if @state == 'disconnected' && event == 'connect'
      @state = 'connected'
      @events << event
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'disconnected'
      @events << event
    elsif @state == 'connected' && event == 'data'
      @state = 'processing'
      @events << event
    elsif @state == 'processing' && event == 'complete'
      @state = 'connected'
      @events << event
    else
      @events << 'invalid'
    end
  end

  def get_state
    @state
  end

  def get_events
    @events
  end
end

class EventGenerator
  def initialize
    @events = ['connect', 'data', 'complete', 'disconnect']
  end

  def generate
    require 'securerandom'
    @events.sample
  end
end

class SystemMonitor
  def initialize(state_machine, event_generator)
    @state_machine = state_machine
    @event_generator = event_generator
  end

  def run
    loop do
      event = @event_generator.generate
      @state_machine.transition(event)
    end
  end
end

def main
  state_machine = NetworkStateMachine.new
  event_generator = EventGenerator.new
  monitor = SystemMonitor.new(state_machine, event_generator)
  monitor.run
end

main