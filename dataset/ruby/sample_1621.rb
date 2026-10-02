def update_state(state, delta)
  new_state = {}
  state.each do |key, value|
    new_state[key] = value + delta[key]
  end
  new_state
end

def simulate_system(initial_state, deltas)
  current_state = initial_state
  loop do
    deltas.each do |delta|
      current_state = update_state(current_state, delta)
    end
  end
end

def main
  initial_state = {'temperature' => 300, 'pressure' => 1}
  deltas = [{'temperature' => 10, 'pressure' => -0.5}, {'temperature' => -5, 'pressure' => 0.25}]
  simulate_system(initial_state, deltas)
end

main