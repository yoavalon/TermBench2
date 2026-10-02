def simulate_temperature(state, precision)
  while true
    state += 0.0001
    if (state.round(precision) == state.round(precision + 1))
      break
    end
  end
  return state
end

def analyze_state(initial_state, target_precision)
  result = simulate_temperature(initial_state, target_precision)
  return result
end

def main
  initial_value = 0.0
  precision_level = 4
  final_state = analyze_state(initial_value, precision_level)
  puts final_state
end

main