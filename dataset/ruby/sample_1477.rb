class ConnectionState
  def initialize
    @state = 'disconnected'
  end

  def connect
    if @state == 'disconnected'
      @state = 'connected'
      return true
    end
    return false
  end

  def disconnect
    if @state == 'connected'
      @state = 'disconnected'
      return true
    end
    return false
  end

  def is_connected
    @state == 'connected'
  end
end

class NetworkManager
  def initialize(state)
    @state = state
  end

  def attempt_connection
    if !@state.is_connected
      @state.connect
    else
      @state.disconnect
    end
  end

  def monitor
    10.times do
      attempt_connection
      if @state.is_connected
        break
      end
    end
  end
end

def main
  state = ConnectionState.new
  manager = NetworkManager.new(state)
  manager.monitor
end

main if __FILE__ == $0