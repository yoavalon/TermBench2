ruby
class NetworkState

  def initialize
    @state = 'idle'
  end

  def transition(event)
    if @state == 'idle' && event == 'connect'
      @state = 'connected'
    elsif @state == 'connected' && event == 'data'
      @state = 'transmitting'
    elsif @state == 'transmitting' && event == 'disconnect'
      @state = 'idle'
    else
      @state = 'error'
    end
  end

end

class NetworkManager

  def initialize
    @state_machine = NetworkState.new
  end

  def process_events(events)
    events.each do |event|
      @state_machine.transition(event)
      if @state_machine.instance_variable_get(:@state) == 'error'
        return false
      end
    end
    return true
  end

end

class EventGenerator

  def initialize
    @events = ['connect', 'data', 'disconnect']
  end

  def generate
    @events
  end

end

def main
  event_gen = EventGenerator.new
  network_mgr = NetworkManager.new
  events = event_gen.generate
  success = network_mgr.process_events(events)
  puts success
end

main