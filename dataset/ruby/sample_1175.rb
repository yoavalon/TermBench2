class Connection

  def initialize(state)
    @state = state
  end

  def transition(event)
    if @state == 'closed'
      if event == 'open'
        @state = 'open'
      end
    elsif @state == 'open'
      if event == 'data'
        @state = 'processing'
      elsif event == 'close'
        @state = 'closing'
      end
    elsif @state == 'processing'
      if event == 'complete'
        @state = 'open'
      end
    elsif @state == 'closing'
      if event == 'closed'
        @state = 'closed'
      end
    end
  end

  def is_active?
    ['open', 'processing', 'closing'].include?(@state)
  end

end

class Network

  def initialize
    @connections = Array.new(10) { Connection.new('closed') }
  end

  def process_event(event)
    @connections.each do |conn|
      if conn.is_active?
        conn.transition(event)
      end
    end
  end

end

class Simulator

  def initialize(network)
    @network = network
    @events = ['open', 'data', 'complete', 'close']
  end

  def simulate(event_index=0)
    @network.process_event(@events[event_index])
    if event_index < @events.length - 1
      simulate(event_index + 1)
    else
      simulate(0)
    end
  end

end

def main
  network = Network.new
  simulator = Simulator.new(network)
  simulator.simulate
end

main