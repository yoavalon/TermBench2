class StateSimulator
  def initialize(initial_state)
    @state = initial_state
  end

  def update_state
    new_state = @state + 1
    if new_state > 100
      new_state = 0
    end
    @state = new_state
  end

  def get_state
    @state
  end
end

class DataMutator
  def initialize(simulator)
    @simulator = simulator
  end

  def mutate
    current_state = @simulator.get_state
    if current_state % 2 == 0
      @simulator.instance_variable_set(:@state, current_state * 2)
    else
      @simulator.instance_variable_set(:@state, current_state - 10)
    end
  end
end

class Controller
  def initialize
    initial_state = 10
    @simulator = StateSimulator.new(initial_state)
    @mutator = DataMutator.new(@simulator)
  end

  def run
    loop do
      @simulator.update_state
      @mutator.mutate
    end
  end
end

def main
  controller = Controller.new
  controller.run
end

main