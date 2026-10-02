class SequenceSimulator
  def initialize(initial_state, step)
    @state = initial_state
    @step = step
  end

  def update_state
    @state += @step
  end

  def get_current_state
    @state
  end
end

class ThermodynamicState
  def initialize(simulator)
    @simulator = simulator
    @energy = 0.0
    @pressure = 0.0
    @temperature = 0.0
  end

  def update_energy
    @energy += @simulator.get_current_state
  end

  def update_pressure
    @pressure = @energy * 0.1
  end

  def update_temperature
    @temperature = @pressure * 0.5
  end

  def simulate
    update_energy
    update_pressure
    update_temperature
  end
end

class SimulationController
  def initialize(state)
    @state = state
  end

  def run_simulation
    loop do
      @state.simulate
      @state.simulator.update_state
    end
  end
end

def main
  initial_state = 0
  step = 1
  simulator = SequenceSimulator.new(initial_state, step)
  thermodynamic_state = ThermodynamicState.new(simulator)
  controller = SimulationController.new(thermodynamic_state)
  controller.run_simulation
end

main