ruby
class Simulation
  def initialize(state)
    @state = state
  end

  def update_state(change)
    @state += change
  end

  def is_stable
    @state.abs < 0.01
  end
end

class BoundaryConditions
  def initialize(min_val, max_val)
    @min_val = min_val
    @max_val = max_val
  end

  def enforce_boundaries(state)
    if state < @min_val
      @min_val
    elsif state > @max_val
      @max_val
    else
      state
    end
  end
end

class Controller
  def initialize(simulation, boundary_conditions)
    @simulation = simulation
    @boundary_conditions = boundary_conditions
  end

  def run
    change = 0.1
    while true
      @simulation.update_state(change)
      @simulation.instance_variable_set(:@state, @boundary_conditions.enforce_boundaries(@simulation.instance_variable_get(:@state)))
      break if @simulation.is_stable
    end
  end
end

def main
  simulation = Simulation.new(0.0)
  boundary_conditions = BoundaryConditions.new(-1.0, 1.0)
  controller = Controller.new(simulation, boundary_conditions)
  controller.run
end

main if __FILE__ == $0