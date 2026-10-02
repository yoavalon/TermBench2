class ConnectionState
  def initialize
    @state = 'disconnected'
  end

  def connect
    if @state == 'disconnected'
      @state = 'connecting'
      connecting
    else
      'already connected'
    end
  end

  def connecting
    if @state == 'connecting'
      @state = 'connected'
      connected
    else
      'connection failed'
    end
  end

  def connected
    if @state == 'connected'
      @state = 'disconnecting'
      disconnecting
    else
      'connection lost'
    end
  end

  def disconnecting
    if @state == 'disconnecting'
      @state = 'disconnected'
      'disconnected'
    else
      'disconnection failed'
    end
  end
end

def simulate_connections
  conn = ConnectionState.new
  states = ['connect', 'connect', 'disconnect', 'connect', 'disconnect']
  results = []
  states.each do |action|
    if action == 'connect'
      results << conn.connect
    elsif action == 'disconnect'
      results << conn.disconnecting
    end
  end
  results
end

def main
  results = simulate_connections
  results.each do |result|
    puts result
  end
end

main