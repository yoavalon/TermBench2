class NetworkConnection
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
    return @state == 'connected'
  end
end

def monitor_connection(conn)
  loop do
    if conn.is_connected
      puts 'Connection is active.'
    else
      puts 'No active connection.'
      conn.connect
    end
  end
end

def main
  conn = NetworkConnection.new
  monitor_connection(conn)
end

main