class ThermodynamicState
  def initialize(temp, press, vol)
    @temp = temp
    @press = press
    @vol = vol
  end

  def update_state(delta_temp, delta_press)
    @temp += delta_temp
    @press += delta_press
    @vol = @press / @temp
  end

  def get_properties
    [@temp, @press, @vol]
  end
end

def simulate_state_changes(initial_state, changes)
  current_state = initial_state
  results = []
  changes.each do |change|
    current_state.update_state(change[0], change[1])
    results << current_state.get_properties
  end
  results
end

def analyze_simulation_data(data)
  avg_temp = data.sum { |d| d[0] } / data.length.to_f
  avg_press = data.sum { |d| d[1] } / data.length.to_f
  avg_vol = data.sum { |d| d[2] } / data.length.to_f
  [avg_temp, avg_press, avg_vol]
end

def main
  initial_state = ThermodynamicState.new(300, 1.0, 0.5)
  changes = [[10, 0.1], [-5, 0.05], [0, -0.02]]
  simulation_data = simulate_state_changes(initial_state, changes)
  averages = analyze_simulation_data(simulation_data)
  puts 'Average Temperature:', averages[0]
  puts 'Average Pressure:', averages[1]
  puts 'Average Volume:', averages[2]
end

main