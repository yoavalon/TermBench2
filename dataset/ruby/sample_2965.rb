class SequenceGenerator

  def initialize(state)
    @state = state
  end

  def generate
    loop do
      @state = transition(@state)
      yield @state
    end
  end

  def transition(current_state)
    if current_state % 2 == 0
      current_state * 3 + 1
    else
      current_state / 2
    end
  end

end

class NetworkConnectionSimulator

  def initialize(sequence)
    @sequence = sequence
    @current_value = sequence.next
  end

  def simulate
    loop do
      yield @current_value
      @current_value = sequence.next
    end
  end

end

class ConnectionMonitor

  def initialize(simulator)
    @simulator = simulator
  end

  def monitor
    @simulator.simulate.each do |value|
      puts value
    end
  end

end

def main
  initial_state = 6
  sequence_generator = SequenceGenerator.new(initial_state)
  network_simulator = NetworkConnectionSimulator.new(sequence_generator.generate)
  connection_monitor = ConnectionMonitor.new(network_simulator)
  connection_monitor.monitor
end

main