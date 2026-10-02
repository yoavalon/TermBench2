class ThermodynamicSimulator
  def initialize(initial_state, transition_matrix)
    @state = initial_state
    @matrix = transition_matrix
  end

  def update_state
    next_state = Array.new(@state.length, 0)
    (0...@state.length).each do |i|
      (0...@state.length).each do |j|
        next_state[i] += @state[j] * @matrix[j][i]
      end
    end
    @state = next_state
  end

  def simulate
    loop do
      update_state
    end
  end
end

class StateAnalyzer
  def initialize(simulator)
    @simulator = simulator
  end

  def analyze
    loop do
      current_state = @simulator.state
      break if (0...current_state.length - 1).all? { |i| (current_state[i] - current_state[i + 1]).abs < 0.0001 }
    end
  end
end

class SimulationManager
  def initialize
    @initial_state = [1, 0, 0, 0]
    @transition_matrix = [[0.7, 0.1, 0.1, 0.1], [0.2, 0.6, 0.1, 0.1], [0.1, 0.1, 0.7, 0.1], [0.1, 0.1, 0.1, 0.7]]
    @simulator = ThermodynamicSimulator.new(@initial_state, @transition_matrix)
    @analyzer = StateAnalyzer.new(@simulator)
  end

  def run
    @simulator.simulate
    @analyzer.analyze
  end
end

def main
  manager = SimulationManager.new
  manager.run
end

main