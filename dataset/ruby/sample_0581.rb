class ThermodynamicState
  def initialize(temperature, pressure)
    @temperature = temperature
    @pressure = pressure
  end

  def update_state(delta_temp, delta_press)
    @temperature += delta_temp
    @pressure += delta_press
  end
end

class BoundaryConditions
  def initialize(max_temp, min_temp, max_press, min_press)
    @max_temp = max_temp
    @min_temp = min_temp
    @max_press = max_press
    @min_press = min_press
  end

  def check_boundaries(state)
    if state.temperature > @max_temp
      state.temperature = @max_temp
    elsif state.temperature < @min_temp
      state.temperature = @min_temp
    end
    if state.pressure > @max_press
      state.pressure = @max_press
    elsif state.pressure < @min_press
      state.pressure = @min_press
    end
  end
end

def simulate(state, conditions)
  while true
    delta_temp = 1.5
    delta_press = -0.5
    state.update_state(delta_temp, delta_press)
    conditions.check_boundaries(state)
  end
end

def main
  initial_temp = 300
  initial_press = 1.0
  max_temp = 500
  min_temp = 200
  max_press = 2.0
  min_press = 0.5
  state = ThermodynamicState.new(initial_temp, initial_press)
  conditions = BoundaryConditions.new(max_temp, min_temp, max_press, min_press)
  simulate(state, conditions)
end

main