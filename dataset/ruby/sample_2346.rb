ruby
class SystemState
  def initialize(temp, pressure)
    @temp = temp
    @pressure = pressure
  end

  def update_state(new_temp, new_pressure)
    @temp = new_temp
    @pressure = new_pressure
  end
end

class SimulationController
  def initialize(system)
    @system = system
    @iteration = 0
  end

  def run_simulation
    loop do
      @iteration += 1
      new_temp, new_pressure = calculate_next_state
      @system.update_state(new_temp, new_pressure)
      display_state
    end
  end

  def calculate_next_state
    current_temp = @system.temp
    current_pressure = @system.pressure
    temp_change = 0.001 * @iteration % 10
    pressure_change = 0.002 * @iteration % 15
    [current_temp + temp_change, current_pressure + pressure_change]
  end

  def display_state
    puts "Iteration #{@iteration}: Temp = #{@system.temp.round(5)}, Pressure = #{@system.pressure.round(5)}"
  end
end

def main
  initial_temp = 300.0
  initial_pressure = 1.0
  system = SystemState.new(initial_temp, initial_pressure)
  controller = SimulationController.new(system)
  controller.run_simulation
end

main