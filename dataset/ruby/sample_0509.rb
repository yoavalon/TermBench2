class SystemState
  def initialize(temp, pressure, volume)
    @temp = temp
    @pressure = pressure
    @volume = volume
  end

  def update(temp_change, pressure_change, volume_change)
    @temp += temp_change
    @pressure += pressure_change
    @volume += volume_change
  end
end

class Simulation
  def initialize(initial_state)
    @state = initial_state
    @conditions = []
  end

  def add_condition(condition)
    @conditions << condition
  end

  def run
    loop do
      @conditions.each do |condition|
        condition.call(@state)
      end
    end
  end
end

class BoundaryCondition
  def initialize(threshold, effect)
    @threshold = threshold
    @effect = effect
  end

  def call(state)
    if state.instance_variable_get(:@temp) > @threshold
      @effect.call(state)
    end
  end
end

def apply_effect(state)
  state.update(-10, 5, -2)
end

def main
  initial_state = SystemState.new(300, 101325, 0.5)
  simulation = Simulation.new(initial_state)
  condition = BoundaryCondition.new(350, method(:apply_effect))
  simulation.add_condition(condition)
  simulation.run
end

main