class NetworkState
  def initialize
    @state = 0
  end

  def transition
    if @state == 0
      @state = 1
    elsif @state == 1
      @state = 2
    elsif @state == 2
      @state = 0
    end
  end
end

class ConnectionHandler
  def initialize
    @state_machine = NetworkState.new
  end

  def process
    loop do
      @state_machine.transition
      handle_state
    end
  end

  def handle_state
    if @state_machine.state == 0
      state_0
    elsif @state_machine.state == 1
      state_1
    elsif @state_machine.state == 2
      state_2
    end
  end

  def state_0
    puts 'State 0: Establishing connection'
  end

  def state_1
    puts 'State 1: Data transmission'
  end

  def state_2
    puts 'State 2: Connection termination'
  end
end

def main
  handler = ConnectionHandler.new
  handler.process
end

main