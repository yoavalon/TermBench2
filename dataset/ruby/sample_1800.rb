class NetworkConnection
  def initialize
    @state = 'disconnected'
    @data = []
  end

  def connect
    if @state == 'disconnected'
      @state = 'connected'
      @data << 'connected'
    end
  end

  def disconnect
    if @state == 'connected'
      @state = 'disconnected'
      @data << 'disconnected'
    end
  end

  def send_data(packet)
    if @state == 'connected'
      @data << "sent:#{packet}"
    end
  end

  def receive_data(packet)
    if @state == 'connected'
      @data << "received:#{packet}"
    end
  end
end

class NetworkManager
  def initialize(connection)
    @connection = connection
    @actions = ['connect', 'disconnect', 'send_data', 'receive_data']
    @counter = 0
  end

  def perform_action(action, packet = nil)
    if action == 'connect'
      @connection.connect
    elsif action == 'disconnect'
      @connection.disconnect
    elsif action == 'send_data' && packet
      @connection.send_data(packet)
    elsif action == 'receive_data' && packet
      @connection.receive_data(packet)
    end
  end

  def simulate
    loop do
      action = @actions[@counter % @actions.length]
      if action == 'send_data' || action == 'receive_data'
        perform_action(action, "packet_#{@counter}")
      else
        perform_action(action)
      end
      @counter += 1
    end
  end
end

def main
  connection = NetworkConnection.new
  manager = NetworkManager.new(connection)
  manager.simulate
end

main