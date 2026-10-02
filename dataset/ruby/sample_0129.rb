ruby
def update_state(state, params)
  params.each do |key, value|
    state[key] += value
  end
  state
end

def check_stability(state, thresholds)
  thresholds.each do |key, value|
    if state[key].abs > value
      return false
    end
  end
  true
end

def simulate(state, params, thresholds, steps)
  steps.times do
    state = update_state(state, params)
    return state unless check_stability(state, thresholds)
  end
  state
end

def main
  state = {'temp' => 0, 'pressure' => 0}
  params = {'temp' => 0.1, 'pressure' => -0.05}
  thresholds = {'temp' => 1, 'pressure' => 0.5}
  steps = 100
  final_state = simulate(state, params, thresholds, steps)
  puts final_state
end

main