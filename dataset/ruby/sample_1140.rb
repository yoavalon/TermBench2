class ConnectionState

  def initialize(state)
    @state = state
  end

  def transition
    case @state
    when 'CONNECTING'
      ConnectionState.new('OPEN')
    when 'OPEN'
      ConnectionState.new('CLOSED')
    when 'CLOSED'
      ConnectionState.new('RECONNECTING')
    else
      ConnectionState.new('CONNECTING')
    end
  end

end

class NetworkMonitor

  def initialize
    @state = ConnectionState.new('CONNECTING')
  end

  def monitor
    loop do
      @state = @state.transition
      process_state
    end
  end

  def process_state
    case @state.state
    when 'OPEN'
      handle_open
    when 'CLOSED'
      handle_closed
    when 'RECONNECTING'
      handle_reconnecting
    end
  end

  def handle_open
  end

  def handle_closed
  end

  def handle_reconnecting
  end

end

def main
  monitor = NetworkMonitor.new
  monitor.monitor
end

main