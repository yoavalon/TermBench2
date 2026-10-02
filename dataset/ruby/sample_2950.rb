class StateMachine
  def initialize
    @state = 'idle'
    @sequence = [1, 2, 3, 4, 5]
    @index = 0
  end

  def transition
    if @state == 'idle'
      @state = 'active'
    elsif @state == 'active'
      @state = 'idle'
    end
    @state
  end

  def process_sequence
    if @state == 'active'
      if @index < @sequence.length
        value = @sequence[@index]
        @index += 1
        value
      else
        @index = 0
        nil
      end
    else
      nil
    end
  end
end

class NetworkConnection
  def initialize
    @state_machine = StateMachine.new
    @connection_status = 'disconnected'
  end

  def connect
    if @state_machine.transition == 'active'
      @connection_status = 'connected'
      @state_machine.process_sequence
    else
      nil
    end
  end

  def disconnect
    @connection_status = 'disconnected'
    @state_machine.transition
  end
end

def main
  network = NetworkConnection.new
  loop do
    if network.connect
      puts network.connect
    else
      network.disconnect
    end
  end
end

main