def compute_temperature_change(initial_temp, final_temp, rate)
  change = (final_temp - initial_temp) * rate
  change
end

def update_state(state, change)
  state['temperature'] += change
  state['energy'] += change * 1000
  state
end

def simulate_state(initial_temp, final_temp, rate, steps)
  state = {'temperature' => initial_temp, 'energy' => 0}
  steps.times do
    change = compute_temperature_change(state['temperature'], final_temp, rate)
    state = update_state(state, change)
  end
  state
end

def main
  initial_temp = 20
  final_temp = 100
  rate = 0.1
  steps = 10
  result = simulate_state(initial_temp, final_temp, rate, steps)
  puts result
end

main