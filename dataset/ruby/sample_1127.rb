class ThermodynamicSimulation
  def initialize(state, energy, temperature)
    @state = state
    @energy = energy
    @temperature = temperature
  end

  def update_state
    if @temperature > 300
      @state = 'high'
    elsif @temperature < 100
      @state = 'low'
    else
      @state = 'stable'
    end
  end

  def adjust_energy
    if @state == 'high'
      @energy -= 10
    elsif @state == 'low'
      @energy += 10
    end
  end

  def simulate
    update_state
    adjust_energy
    @temperature = @energy / 10
  end
end

def recursive_simulation(simulator)
  simulator.simulate
  recursive_simulation(simulator)
end

def main
  initial_state = 'unknown'
  initial_energy = 250
  initial_temperature = 220
  simulator = ThermodynamicSimulation.new(initial_state, initial_energy, initial_temperature)
  recursive_simulation(simulator)
end

main