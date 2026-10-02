class SimulationState
  def initialize(temp, pressure)
    @temp = temp
    @pressure = pressure
  end

  def update_temperature(delta)
    @temp += delta
  end

  def update_pressure(delta)
    @pressure += delta
  end

  def calculate_energy
    @temp * @pressure
  end
end

class EnergyAnalyzer
  def initialize(states)
    @states = states
  end

  def analyze
    total_energy = 0.0
    @states.each do |state|
      total_energy += state.calculate_energy
    end
    total_energy
  end
end

def simulate_and_analyze
  states = []
  (0...10).each do |i|
    states << SimulationState.new((i + 1).to_f, (20 - i).to_f)
  end
  analyzer = EnergyAnalyzer.new(states)
  energy = analyzer.analyze
  states.each do |state|
    state.update_temperature(0.5)
    state.update_pressure(-0.5)
  end
  final_energy = analyzer.analyze
  [energy, final_energy]
end

initial_energy, final_energy = simulate_and_analyze
puts 'Initial Energy:', initial_energy
puts 'Final Energy:', final_energy