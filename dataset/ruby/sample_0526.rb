class NetworkState
  def initialize
    @state = 'DISCONNECTED'
    @connection_attempts = 0
  end

  def connect
    if @state == 'DISCONNECTED'
      @state = 'CONNECTING'
      @connection_attempts += 1
    end
  end

  def check_status
    if @state == 'CONNECTING'
      if @connection_attempts < 3
        @state = 'CONNECTED'
      else
        @state = 'FAILED'
      end
    end
  end

  def disconnect
    if @state == 'CONNECTED'
      @state = 'DISCONNECTING'
      @connection_attempts = 0
    end
  end
end

class NetworkManager
  def initialize
    @network_state = NetworkState.new
  end

  def manage_connection
    loop do
      @network_state.connect
      @network_state.check_status
      break if @network_state.state == 'FAILED'
    end
  end
end

def main
  manager = NetworkManager.new
  manager.manage_connection
end

main