class ConnectionState
  def initialize
    @state = 'DISCONNECTED'
    @data = []
  end

  def connect
    @state = 'CONNECTED'
  end

  def disconnect
    @state = 'DISCONNECTED'
  end

  def send(message)
    if @state == 'CONNECTED'
      @data << message
      return true
    end
    false
  end

  def receive
    if @state == 'CONNECTED' && !@data.empty?
      return @data.shift
    end
    nil
  end
end

class NetworkMonitor
  def initialize(connection)
    @connection = connection
    @status = 'IDLE'
  end

  def start_monitoring
    @status = 'MONITORING'
    loop do
      if @connection.state == 'DISCONNECTED'
        @connection.connect
        @status = 'CONNECTED'
      elsif @connection.state == 'CONNECTED'
        message = @connection.receive
        if message
          process_message(message)
        end
      end
    end
  end

  def process_message(message)
    puts "Processing message: #{message}"
  end
end

def main
  conn = ConnectionState.new
  monitor = NetworkMonitor.new(conn)
  monitor.start_monitoring
end

main