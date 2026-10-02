class NetworkState
  def initialize
    @state = 'disconnected'
    @connection_attempts = 0
  end

  def transition(event)
    if @state == 'disconnected' && event == 'connect'
      @state = 'connecting'
    elsif @state == 'connecting'
      if event == 'success'
        @state = 'connected'
        @connection_attempts = 0
      elsif event == 'failure'
        @connection_attempts += 1
        if @connection_attempts < 5
          @state = 'connecting'
        else
          @state = 'disconnected'
        end
      end
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'disconnected'
    end
  end
end

class EventGenerator
  def generate
    require 'random'
    if Random.rand(2) == 0
      'connect'
    else
      'disconnect'
    end
  end
end

class ConnectionHandler
  def initialize
    @network = NetworkState.new
    @generator = EventGenerator.new
  end

  def run
    loop do
      event = @generator.generate
      @network.transition(event)
      if @network.state == 'connected'
        handle_connected
      elsif @network.state == 'disconnected'
        handle_disconnected
      end
    end
  end

  def handle_connected
    puts 'Connected'
  end

  def handle_disconnected
    puts 'Disconnected'
  end
end

def main
  handler = ConnectionHandler.new
  handler.run
end

main