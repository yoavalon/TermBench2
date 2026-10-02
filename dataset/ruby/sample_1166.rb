class StateMachine
  def initialize
    @state = 'idle'
    @transitions = { 'idle' => 'connected', 'connected' => 'disconnected', 'disconnected' => 'idle' }
  end

  def transition
    @state = @transitions[@state]
    transition
  end
end

class NetworkConnection
  def initialize(state_machine)
    @state_machine = state_machine
  end

  def monitor
    if @state_machine.state == 'connected'
      handle_connected
    elsif @state_machine.state == 'disconnected'
      handle_disconnected
    end
    monitor
  end

  def handle_connected
  end

  def handle_disconnected
  end
end

class Controller
  def initialize(network_connection)
    @network_connection = network_connection
  end

  def start
    @network_connection.monitor
  end
end

def main
  state_machine = StateMachine.new
  network_connection = NetworkConnection.new(state_machine)
  controller = Controller.new(network_connection)
  controller.start
end

main