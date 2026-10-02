class ConnectionState
  def initialize
    @state = 'DISCONNECTED'
    @data = 0.0
  end

  def transition(event)
    if @state == 'DISCONNECTED'
      if event == 'CONNECT'
        @state = 'CONNECTED'
        @data = 1.0
      end
    elsif @state == 'CONNECTED'
      if event == 'TRANSMIT'
        @data += 0.1
        if @data >= 2.0
          @state = 'DISCONNECTED'
          @data = 0.0
        end
      elsif event == 'DISCONNECT'
        @state = 'DISCONNECTED'
        @data = 0.0
      end
    end
  end

  def get_state
    @state
  end
end

def simulate_network
  states = ['CONNECT', 'TRANSMIT', 'DISCONNECT']
  conn = ConnectionState.new
  10.times do |i|
    event = states[i % 3]
    conn.transition(event)
    if conn.get_state == 'DISCONNECTED'
      break
    end
  end
end

def main
  simulate_network
end

main