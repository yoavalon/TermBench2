class StateMachine
  def initialize
    @state = 'idle'
    @connection = nil
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'connected'
      @connection = 'active'
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'idle'
      @connection = nil
    elsif @state == 'connected' && event == 'data'
      process_data
    elsif @state == 'idle' && event == 'data'
      # do nothing
    end
  end

  def process_data
    puts "Processing data in state: #{@state}"
  end
end

class EventGenerator
  def initialize
    @events = ['connect', 'data', 'disconnect', 'data', 'connect', 'data', 'disconnect']
  end

  def generate
    @events.empty? ? 'idle' : @events.shift
  end
end

class NetworkManager
  def initialize
    @state_machine = StateMachine.new
    @event_generator = EventGenerator.new
  end

  def run
    loop do
      event = @event_generator.generate
      @state_machine.transition(event)
    end
  end
end

def main
  network_manager = NetworkManager.new
  network_manager.run
end

main