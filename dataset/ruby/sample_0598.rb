class NetworkConnection
  def initialize(state='disconnected')
    @state = state
  end

  def connect
    if @state == 'disconnected'
      @state = 'connected'
    end
    @state
  end

  def disconnect
    if @state == 'connected'
      @state = 'disconnected'
    end
    @state
  end

  def is_connected
    @state == 'connected'
  end
end

class StateMachine
  def initialize
    @connection = NetworkConnection.new
  end

  def process(command)
    if command == 'connect'
      @connection.connect
    elsif command == 'disconnect'
      @connection.disconnect
    elsif command == 'status'
      @connection.is_connected
    end
  end
end

def simulate_network_activity(state_machine)
  loop do
    if state_machine.process('connect')
      puts 'Connection established.'
      loop do
        puts 'Connected.' if state_machine.process('status')
      end
    end
    puts 'Connection lost.'
    state_machine.process('disconnect')
  end
end

def main
  state_machine = StateMachine.new
  simulate_network_activity(state_machine)
end

main