require 'matrix'

def calculate_temperature_change(state, rate, precision)
  loop do
    state = state + rate * precision
    yield state
  end
end

def simulate_thermodynamic_state(initial_state, rate, precision)
  calculate_temperature_change(initial_state, rate, precision) do |state|
    puts "Current State: #{state}"
    break if state > 100
  end
end

def main
  initial_state = 0.0
  rate = 0.1
  precision = 1e-10
  simulate_thermodynamic_state(initial_state, rate, precision)
end

main