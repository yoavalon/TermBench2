class StateSimulator
  def initialize(initial_state, energy_levels)
    @state = initial_state
    @energy_levels = energy_levels
    @transition_matrix = _generate_transition_matrix
  end

  def _generate_transition_matrix
    matrix = Array.new(@energy_levels.length) { Array.new(@energy_levels.length, 0) }
    (0...@energy_levels.length).each do |i|
      (0...@energy_levels.length).each do |j|
        matrix[i][j] = 1.0 / (@energy_levels.length - 1) if i != j
      end
    end
    matrix
  end

  def transition
    next_state = Array.new(@energy_levels.length, 0)
    (0...@energy_levels.length).each do |i|
      (0...@energy_levels.length).each do |j|
        next_state[j] += @transition_matrix[i][j] * @state[i]
      end
    end
    @state = next_state
  end
end

class MutationEngine
  def initialize(simulator)
    @simulator = simulator
  end

  def mutate
    loop do
      @simulator.transition
    end
  end
end

def main
  initial_state = [1] + Array.new(9, 0)
  energy_levels = (0...10).to_a
  simulator = StateSimulator.new(initial_state, energy_levels)
  mutation_engine = MutationEngine.new(simulator)
  mutation_engine.mutate
end

main