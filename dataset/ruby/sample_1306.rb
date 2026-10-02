def update_state(state, params)
  state['temperature'] += params['heat']
  state['pressure'] += params['pressure_change']
  state
end

def simulate_thermodynamics(initial_state, params, steps)
  steps.times do
    initial_state = update_state(initial_state, params)
  end
  initial_state
end

def main
  state = {'temperature' => 300, 'pressure' => 1}
  params = {'heat' => 10, 'pressure_change' => 2}
  steps = 5
  final_state = simulate_thermodynamics(state, params, steps)
  puts final_state
end

main