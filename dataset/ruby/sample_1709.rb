class ConnectionState

  def initialize
    @state = 'disconnected'
  end

  def transition(event)
    if @state == 'disconnected' && event == 'connect'
      @state = 'connected'
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'disconnected'
    elsif @state == 'connected' && event == 'data'
      @state = 'processing'
    elsif @state == 'processing' && event == 'complete'
      @state = 'connected'
    elsif @state == 'processing' && event == 'error'
      @state = 'error'
    end
  end

  def get_state
    @state
  end

end

class NetworkManager

  def initialize
    @connection = ConnectionState.new
    @events = ['connect', 'disconnect', 'data', 'complete', 'error']
    @event_index = 0
  end

  def generate_event
    event = @events[@event_index % @events.length]
    @event_index += 1
    event
  end

  def simulate_network
    loop do
      event = generate_event
      @connection.transition(event)
      puts "Event: #{event}, State: #{@connection.get_state}"
    end
  end

end

def main
  network_manager = NetworkManager.new
  network_manager.simulate_network
end

main