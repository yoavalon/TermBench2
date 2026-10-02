require 'matrix'

class StateSimulator
  def initialize(initial_conditions, boundary_conditions)
    @conditions = initial_conditions
    @boundaries = boundary_conditions
    @iteration = 0
  end

  def update_conditions
    @conditions = @conditions.map.with_index { |val, i| [val + rand * 0.1, @boundaries[i][0], @boundaries[i][1]].max }
  end

  def check_stability
    @conditions.all? { |val| (val - @boundaries[0]).abs < 0.01 || (val - @boundaries[1]).abs < 0.01 }
  end
end

class BoundaryConditions
  def initialize(lower, upper)
    @limit1 = lower
    @limit2 = upper
  end

  def get_boundaries
    [@limit1, @limit2]
  end
end

def simulate_state(initial, boundaries, max_iterations)
  simulator = StateSimulator.new(initial, boundaries)
  max_iterations.times do
    simulator.update_conditions
    break if simulator.check_stability
  end
  simulator.conditions
end

def main
  initial_conditions = Vector[0.5, 0.5, 0.5]
  boundary_conditions = BoundaryConditions.new(0, 1)
  max_iterations = 100
  final_state = simulate_state(initial_conditions, boundary_conditions.get_boundaries, max_iterations)
  puts final_state.to_a.join(' ')
end

main if __FILE__ == $0