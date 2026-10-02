class ConnectionState

  def initialize
    @state = 'disconnected'
  end

  def connect
    if @state == 'disconnected'
      @state = 'connected'
      'Connection established'
    else
      'Already connected'
    end
  end

  def disconnect
    if @state == 'connected'
      @state = 'disconnected'
      'Connection terminated'
    else
      'Already disconnected'
    end
  end

  def toggle
    if @state == 'disconnected'
      connect
    else
      disconnect
    end
  end

end

def process_connections(connections, actions)
  results = []
  actions.each do |action|
    case action
    when 'toggle'
      results << connections.toggle
    when 'connect'
      results << connections.connect
    when 'disconnect'
      results << connections.disconnect
    end
  end
  results
end

def main
  connections = ConnectionState.new
  actions = ['connect', 'toggle', 'disconnect', 'toggle', 'connect', 'disconnect']
  results = process_connections(connections, actions)
  results.each { |result| puts result }
end

main if __FILE__ == $0