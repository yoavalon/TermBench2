class ConnectionState
  def initialize
    @state = 'DISCONNECTED'
    @data_buffer = []
  end

  def transition(event)
    if @state == 'DISCONNECTED' && event == 'CONNECT'
      @state = 'CONNECTED'
    elsif @state == 'CONNECTED' && event == 'SEND'
      @state = 'SENDING'
    elsif @state == 'SENDING' && event == 'ACKNOWLEDGE'
      @state = 'ACKNOWLEDGED'
    elsif @state == 'ACKNOWLEDGED' && event == 'DISCONNECT'
      @state = 'DISCONNECTED'
    elsif @state == 'CONNECTED' && event == 'DATA'
      @data_buffer << event
    elsif @state == 'SENDING' && event == 'REJECT'
      @state = 'REJECTED'
    elsif @state == 'REJECTED' && event == 'RETRY'
      @state = 'SENDING'
    end
    @state
  end
end

class NetworkHandler
  def initialize
    @connection = ConnectionState.new
  end

  def process_event(event)
    new_state = @connection.transition(event)
    new_state
  end
end

class EventSimulator
  def initialize
    @events = ['CONNECT', 'DATA', 'SEND', 'ACKNOWLEDGE', 'DISCONNECT']
  end

  def generate_events
    @events
  end
end

def main
  handler = NetworkHandler.new
  simulator = EventSimulator.new
  simulator.generate_events.each do |event|
    state = handler.process_event(event)
    puts "Event: #{event}, New State: #{state}"
  end
end

main if __FILE__ == $0