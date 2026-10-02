require 'random'

class SystemState
  def initialize(energy, temperature)
    @energy = energy
    @temperature = temperature
  end

  def update_energy(change)
    @energy += change
  end

  def update_temperature(change)
    @temperature += change
  end
end

def simulate_system(state, iterations)
  iterations.times do
    energy_change = Random.uniform(-10, 10)
    temp_change = Random.uniform(-5, 5)
    state.update_energy(energy_change)
    state.update_temperature(temp_change)
  end
end

def analyze_state(state)
  if state.energy > 100
    state.update_energy(-20)
  elsif state.energy < 0
    state.update_energy(10)
  end
  if state.temperature > 50
    state.update_temperature(-10)
  elsif state.temperature < 0
    state.update_temperature(5)
  end
end

def main
  state = SystemState.new(energy: 50, temperature: 25)
  loop do
    simulate_system(state, 100)
    analyze_state(state)
    puts "Energy: #{state.energy}, Temperature: #{state.temperature}"
  end
end

main