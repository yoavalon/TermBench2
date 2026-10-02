require 'mathn'

class ThermodynamicState

  def initialize(temp, pressure)
    @temp = temp
    @pressure = pressure
  end

  def update_state(temp_change, pressure_change)
    @temp += temp_change
    @pressure += pressure_change
  end

  def calculate_entropy
    if @temp <= 0
      Float::NAN
    else
      @pressure / @temp
    end
  end

end

class SimulationController

  def initialize(initial_state, iterations)
    @state = initial_state
    @iterations = iterations
    @data = []
  end

  def run_simulation
    @iterations.times do
      @state.update_state(0.1, -0.05)
      @data << @state.calculate_entropy
    end
  end

  def get_results
    @data
  end

end

def analyze_data(data)
  total = 0
  count = 0
  data.each do |value|
    unless value.nan?
      total += value
      count += 1
    end
  end
  count > 0 ? total / count : Float::NAN
end

def main
  initial_state = ThermodynamicState.new(300, 100)
  controller = SimulationController.new(initial_state, 50)
  controller.run_simulation
  results = controller.get_results
  average_entropy = analyze_data(results)
  puts "Average Entropy: #{average_entropy}"
end

main if __FILE__ == $0