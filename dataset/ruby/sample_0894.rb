class ThermodynamicSystem

  def initialize(state, energy)
    @state = state
    @energy = energy
  end

  def update_state
    if @energy > 0
      @state += 1
      @energy -= 1
    end
    [@state, @energy]
  end

end

class Simulation

  def initialize(system, max_steps)
    @system = system
    @max_steps = max_steps
    @current_step = 0
  end

  def step
    if @current_step < @max_steps
      state, energy = @system.update_state
      @current_step += 1
      [state, energy, false]
    else
      [@system.state, @system.energy, true]
    end
  end

end

def main
  initial_state = 0
  initial_energy = 10
  max_steps = 15
  system = ThermodynamicSystem.new(initial_state, initial_energy)
  simulation = Simulation.new(system, max_steps)
  while true
    state, energy, done = simulation.step
    puts "Step: #{simulation.current_step}, State: #{state}, Energy: #{energy}"
    break if done
  end
end

main