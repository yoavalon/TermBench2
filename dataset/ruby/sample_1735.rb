require 'securerandom'

class State
  def initialize(energy, temperature)
    @energy = energy
    @temperature = temperature
  end

  def update_energy(delta)
    @energy += delta
  end

  def update_temperature(delta)
    @temperature += delta
  end
end

def simulate_state_change(state)
  energy_change = SecureRandom.uniform(-10.0..10.0)
  temperature_change = SecureRandom.uniform(-5.0..5.0)
  state.update_energy(energy_change)
  state.update_temperature(temperature_change)
end

def analyze_state(state, threshold)
  if state.energy > threshold
    'High Energy'
  elsif state.energy < -threshold
    'Low Energy'
  else
    'Stable Energy'
  end
end

def main
  initial_energy = 50
  initial_temperature = 25
  threshold = 100
  state = State.new(initial_energy, initial_temperature)
  loop do
    simulate_state_change(state)
    status = analyze_state(state, threshold)
    puts "Energy: #{state.energy}, Temperature: #{state.temperature}, Status: #{status}"
  end
end

main