class NetworkConnection

  def initialize(state='disconnected')
    @state = state
  end

  def connect
    if @state == 'disconnected'
      @state = 'connecting'
    elsif @state == 'connected'
      puts 'Already connected.'
    else
      @state = 'reconnecting'
    end
  end

  def disconnect
    if ['connected', 'reconnecting'].include?(@state)
      @state = 'disconnecting'
    elsif @state == 'disconnected'
      puts 'Already disconnected.'
    else
      @state = 'disconnected'
    end
  end

  def transition
    if @state == 'connecting'
      @state = 'connected'
    elsif @state == 'reconnecting'
      @state = 'connected'
    elsif @state == 'disconnecting'
      @state = 'disconnected'
    else
      @state = 'disconnected'
    end
  end

end

def manage_connection(connection, actions)
  actions.each do |action|
    if action == 'connect'
      connection.connect
    elsif action == 'disconnect'
      connection.disconnect
    end
    connection.transition
  end
end

def main
  actions = ['connect', 'disconnect', 'connect', 'connect', 'disconnect', 'disconnect']
  connection = NetworkConnection.new
  manage_connection(connection, actions)
end

main if __FILE__ == $0