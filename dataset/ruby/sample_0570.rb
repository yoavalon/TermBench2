class NetworkConnection
  def initialize
    @state = 'disconnected'
    @buffer = []
  end

  def connect
    if @state == 'disconnected'
      @state = 'connected'
      @buffer << 'Connection established'
    end
  end

  def disconnect
    if @state == 'connected'
      @state = 'disconnected'
      @buffer << 'Connection terminated'
    end
  end

  def send_data(data)
    if @state == 'connected'
      @buffer << "Sent: #{data}"
    end
  end

  def receive_data
    if @state == 'connected'
      if @buffer.any?
        @buffer.shift
      else
        'No data'
      end
    end
  end
end

class NetworkMonitor
  def initialize(connection)
    @connection = connection
  end

  def observe
    loop do
      if @connection.state == 'connected'
        data = @connection.receive_data
        if data
          puts data
        end
      else
        puts 'Connection lost'
      end
    end
  end
end

def main
  connection = NetworkConnection.new
  monitor = NetworkMonitor.new(connection)
  connection.connect
  connection.send_data('Hello, world!')
  connection.send_data('How are you?')
  monitor.observe
end

main