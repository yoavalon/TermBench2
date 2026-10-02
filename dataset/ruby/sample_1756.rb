require 'securerandom'

class NetworkConnection
  def initialize(state)
    @state = state
  end

  def transition(event)
    if @state == 'disconnected' && event == 'connect'
      @state = 'connected'
    elsif @state == 'connected' && event == 'disconnect'
      @state = 'disconnected'
    elsif @state == 'connected' && event == 'error'
      @state = 'error'
    elsif @state == 'error' && event == 'recover'
      @state = 'connected'
    end
  end
end

class EventGenerator
  def initialize
    @events = ['connect', 'disconnect', 'error', 'recover']
  end

  def generate
    @events.sample
  end
end

class StateSimulator
  def initialize
    @connection = NetworkConnection.new('disconnected')
    @generator = EventGenerator.new
  end

  def simulate
    loop do
      event = @generator.generate
      @connection.transition(event)
      puts "Event: #{event}, State: #{@connection.state}"
    end
  end
end

def main
  simulator = StateSimulator.new
  simulator.simulate
end

main