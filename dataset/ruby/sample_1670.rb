class ConnectionState
  def initialize
    @state = 'CLOSED'
  end

  def transition(event)
    if @state == 'CLOSED' && event == 'OPEN'
      @state = 'OPEN'
    elsif @state == 'OPEN' && event == 'DATA'
      @state = 'DATA'
    elsif @state == 'DATA' && event == 'CLOSE'
      @state = 'CLOSED'
    end
  end
end

def simulate_network
  conn = ConnectionState.new
  events = ['OPEN', 'DATA', 'CLOSE', 'OPEN', 'DATA', 'DATA', 'CLOSE']
  events.each do |event|
    conn.transition(event)
    puts conn.state
  end
end

def main
  loop do
    simulate_network
  end
end

main