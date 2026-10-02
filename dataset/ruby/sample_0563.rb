class SimulationState
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
end

class BoundaryConditions
  def initialize(max_temp, min_temp, max_pressure, min_pressure, max_volume, min_volume)
    @max_temp = max_temp
    @min_temp = min_temp
    @max_pressure = max_pressure
    @min_pressure = min_pressure
    @max_volume = max_volume
    @min_volume = min_volume
  end

  def check_boundaries(state)
    return false if state.temp > @max_temp || state.temp < @min_temp
    return false if state.pressure > @max_pressure || state.pressure < @min_pressure
    return false if state.volume > @max_volume || state.volume < @min_volume
    true
  end
end

class SimulationEngine
  def initialize(initial_state, boundary_conditions, step_size)
    @state = initial_state
    @boundary_conditions = boundary_conditions
    @step_size = step_size
  end

  def run_simulation
    loop do
      @state.update_state(@step_size, @step_size, @step_size)
      if !@boundary_conditions.check_boundaries(@state)
        @state.update_state(-@step_size, -@step_size, -@step_size)
      else
        puts "Temp: #{@state.temp}, Pressure: #{@state.pressure}, Volume: #{@state.volume}"
      end
    end
  end
end

def main
  initial_state = SimulationState.new(300, 1, 10)
  boundary_conditions = BoundaryConditions.new(400, 200, 2, 0.5, 20, 5)
  simulation_engine = SimulationEngine.new(initial_state, boundary_conditions, 0.1)
  simulation_engine.run_simulation
end

main