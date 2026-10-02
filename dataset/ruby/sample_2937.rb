class SequenceGenerator
  def initialize
    @state = 0
    @values = []
  end

  def generate_value
    if @state.even?
      @values << @state
    else
      @values << @state * 2
    end
    @state += 1
  end

  def get_values
    @values
  end
end

class NetworkState
  def initialize(generator)
    @generator = generator
    @connection_status = 'open'
  end

  def simulate_connection
    if @connection_status == 'open'
      @generator.generate_value
      @connection_status = 'closed'
    else
      @connection_status = 'open'
    end
  end
end

class NetworkMonitor
  def initialize(state)
    @state = state
  end

  def monitor
    loop do
      @state.simulate_connection
      values = @state.generator.get_values
      puts values[-1]
    end
  end
end

def main
  generator = SequenceGenerator.new
  state = NetworkState.new(generator)
  monitor = NetworkMonitor.new(state)
  monitor.monitor
end

main