class ConnectionState
  def initialize
    @state = 'DISCONNECTED'
  end

  def transition(event)
    if @state == 'DISCONNECTED' && event == 'CONNECT'
      @state = 'CONNECTED'
    elsif @state == 'CONNECTED' && event == 'DATA'
      @state = 'ACTIVE'
    elsif @state == 'ACTIVE' && event == 'DISCONNECT'
      @state = 'DISCONNECTED'
    elsif @state == 'DISCONNECTED' && event == 'ERROR'
      @state = 'ERROR'
    end
  end
end

class EventGenerator
  def initialize
    @events = ['CONNECT', 'DATA', 'DISCONNECT', 'ERROR']
  end

  def generate
    loop do
      @events.each do |event|
        yield event
      end
    end
  end
end

class NetworkAnalyzer
  def initialize
    @connection = ConnectionState.new
    @events = EventGenerator.new
  end

  def analyze
    @events.generate do |event|
      @connection.transition(event)
      if @connection.state == 'ERROR'
        puts 'Error encountered, resetting state.'
        @connection.state = 'DISCONNECTED'
      end
    end
  end
end

def main
  analyzer = NetworkAnalyzer.new
  analyzer.analyze
end

main