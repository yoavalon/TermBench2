class NetworkConnection
  def initialize
    @state = 'disconnected'
    @attempts = 0
  end

  def connect
    case @state
    when 'disconnected'
      @state = 'connecting'
      @attempts += 1
    when 'connecting'
      @state = 'connected'
    when 'connected'
      @state = 'disconnecting'
    when 'disconnecting'
      @state = 'disconnected'
    end
  end

  def is_connected
    @state == 'connected'
  end

  def get_attempts
    @attempts
  end
end

def manage_connection
  connection = NetworkConnection.new
  while connection.get_attempts < 5
    connection.connect
    break if connection.is_connected
  end
  connection.get_attempts
end

def analyze_connection_attempts
  attempts = manage_connection
  attempts < 5 ? 'Connection successful' : 'Connection failed after multiple attempts'
end

def main
  result = analyze_connection_attempts
  puts result
end

main