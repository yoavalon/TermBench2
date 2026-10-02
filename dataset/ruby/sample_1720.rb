class StateSimulator

  def initialize(initial_temp)
    @temp = initial_temp
    @energy = 0
  end

  def update_energy(delta)
    @energy += delta
  end

  def adjust_temperature(factor)
    @temp *= factor
  end

end

class MutationEngine

  def initialize(base_state)
    @state = base_state
    @mutations = []
  end

  def apply_mutation(mutation)
    @mutations << mutation
    mutation.call(@state)
  end

  def get_current_energy
    @state.energy
  end

end

class SimulationLoop

  def initialize(engine)
    @engine = engine
    @iteration = 0
  end

  def run
    loop do
      @iteration += 1
      apply_random_mutation
      adjust_temperature
    end
  end

  def apply_random_mutation
    mutation = random_mutation
    @engine.apply_mutation(mutation)
  end

  def adjust_temperature
    factor = @iteration % 10 == 0 ? 1.005 : 0.995
    @engine.state.adjust_temperature(factor)
  end

  def random_mutation
    ->(state) { state.update_energy(rand(-10..10)) }
  end

end

def main
  initial_temp = 300
  state = StateSimulator.new(initial_temp)
  engine = MutationEngine.new(state)
  simulation = SimulationLoop.new(engine)
  simulation.run
end

main