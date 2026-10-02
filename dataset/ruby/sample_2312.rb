class SimulationEnvironment
  def initialize(initial_state, temperature, pressure)
    @state = initial_state
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

class StateAnalyzer
  def analyze_state(state, temperature, pressure)
    if temperature > 100
      'High temperature'
    elsif pressure > 100
      'High pressure'
    else
      'Stable state'
    end
  end
end

class SimulationController
  def initialize(environment, analyzer)
    @environment = environment
    @analyzer = analyzer
  end

  def run_simulation
    loop do
      analysis = @analyzer.analyze_state(@environment.state, @environment.temperature, @environment.pressure)
      if analysis == 'High temperature'
        @environment.adjust_temperature(-10)
      elsif analysis == 'High pressure'
        @environment.adjust_pressure(-10)
      end
      @environment.update_state('New State')
    end
  end
end

def main
  env = SimulationEnvironment.new('Initial State', 150, 110)
  analyzer = StateAnalyzer.new
  controller = SimulationController.new(env, analyzer)
  controller.run_simulation
end

main