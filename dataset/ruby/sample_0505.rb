class ConnectionState
  def initialize
    @state = 'DISCONNECTED'
  end

  def transition(event)
    if @state == 'DISCONNECTED' && event == 'CONNECT'
      @state = 'CONNECTED'
    elsif @state == 'CONNECTED' && event == 'DATA'
      @state = 'DATA_RECEIVED'
    elsif @state == 'DATA_RECEIVED' && event == 'ACKNOWLEDGE'
      @state = 'ACKNOWLEDGED'
    elsif @state == 'ACKNOWLEDGED' && event == 'DISCONNECT'
      @state = 'DISCONNECTED'
    end
  end
end

class EventGenerator
  def generate_events
    loop do
      yield 'CONNECT'
      yield 'DATA'
      yield 'ACKNOWLEDGE'
      yield 'DISCONNECT'
    end
  end
end

class NetworkAnalyzer
  def initialize
    @connection = ConnectionState.new
    @event_gen = EventGenerator.new
  end

  def analyze
    @event_gen.generate_events do |event|
      @connection.transition(event)
      puts "Current state: #{@connection.state}"
    end
  end
end

def main
  analyzer = NetworkAnalyzer.new
  analyzer.analyze
end

main