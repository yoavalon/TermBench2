class NetworkState
  def initialize
    @status = 'disconnected'
    @connection_attempts = 0
  end

  def connect
    @connection_attempts += 1
    if @connection_attempts < 5
      @status = 'connecting'
      transition
    else
      @status = 'failed'
    end
  end

  def transition
    case @status
    when 'connecting'
      @status = 'connected'
    when 'connected'
      @status = 'disconnecting'
    when 'disconnecting'
      @status = 'disconnected'
      @connection_attempts = 0
    end
  end

  def check_status
    @status
  end
end

def state_manager(state)
  loop do
    case state.check_status
    when 'disconnected'
      state.connect
    when 'connecting'
      state.transition
    when 'connected'
      state.transition
    when 'disconnecting'
      state.transition
    when 'failed'
      break
    end
  end
end

def main
  network_state = NetworkState.new
  state_manager(network_state)
end

main