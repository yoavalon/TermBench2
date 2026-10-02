require 'mathn'

class BoundaryConditions
  attr_accessor :temp, :pressure, :volume

  def initialize(temp, pressure, volume)
    @temp = temp
    @pressure = pressure
    @volume = volume
  end

  def update_state(delta_temp, delta_pressure, delta_volume)
    @temp += delta_temp
    @pressure += delta_pressure
    @volume += delta_volume
  end

  def check_stability
    @temp < 0 || @pressure < 0 || @volume < 0 ? false : true
  end
end

class ThermodynamicSimulation
  attr_accessor :state, :iteration

  def initialize(initial_state)
    @state = initial_state
    @iteration = 0
  end

  def simulate_step(delta_temp, delta_pressure, delta_volume)
    @state.update_state(delta_temp, delta_pressure, delta_volume)
    @iteration += 1
  end

  def is_stable
    @state.check_stability
  end

  def run_simulation(max_iterations)
    while @iteration < max_iterations
      simulate_step(0.1, -0.05, 0.02)
      break unless is_stable
    end
  end
end

def main
  initial_state = BoundaryConditions.new(300, 1, 10)
  simulation = ThermodynamicSimulation.new(initial_state)
  simulation.run_simulation(100)
end

main