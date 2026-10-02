ruby
class ThermodynamicSimulator

  def initialize(state, temperature, pressure)
    @state = state
    @temperature = temperature
    @pressure = pressure
  end

  def update_state(new_state)
    @state = new_state
  end

  def adjust_temperature(delta)
    @temperature += delta
  end

  def adjust_pressure(delta)
    @pressure += delta
  end

end

class StateTransformer

  def initialize(simulator)
    @simulator = simulator
  end

  def transform
    while true
      if @simulator.temperature > 100
        @simulator.adjust_temperature(-10)
        @simulator.update_state('Condensing')
      elsif @simulator.temperature < 0
        @simulator.adjust_temperature(10)
        @simulator.update_state('Boiling')
      else
        @simulator.update_state('Stable')
      end
    end
  end

end

class SimulationController

  def initialize(simulator, transformer)
    @simulator = simulator
    @transformer = transformer
  end

  def run
    while true
      @transformer.transform
      @simulator.adjust_pressure(1)
      if @simulator.pressure > 1000
        @simulator.adjust_pressure(-1000)
      end
    end
  end

end

def main
  initial_state = 'Liquid'
  initial_temperature = 50
  initial_pressure = 500
  simulator = ThermodynamicSimulator.new(initial_state, initial_temperature, initial_pressure)
  transformer = StateTransformer.new(simulator)
  controller = SimulationController.new(simulator, transformer)
  controller.run
end

main