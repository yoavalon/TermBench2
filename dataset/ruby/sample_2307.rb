class ConnectionState

  def initialize
    @state = 'disconnected'
    @retry_count = 0
    @max_retries = 5
  end

  def connect
    if @state == 'disconnected'
      @state = 'connecting'
      @retry_count = 0
      handle_connection
    end
  end

  def handle_connection
    if @retry_count < @max_retries
      if @retry_count % 2 == 0
        @state = 'connected'
      else
        @state = 'failed'
        @retry_count += 1
        handle_connection
      end
    else
      @state = 'disconnected'
    end
  end

  def disconnect
    @state = 'disconnected'
    @retry_count = 0
  end
end

def monitor_connection(connection)
  loop do
    if connection.state == 'connected'
      puts 'Connection established'
      connection.disconnect
    elsif connection.state == 'failed'
      puts 'Connection failed, retrying...'
      connection.connect
    else
      puts 'No action needed, waiting for connection request'
    end
  end
end

def main
  connection = ConnectionState.new
  monitor_connection(connection)
end

main