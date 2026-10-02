def calculate_temperature_change(initial_temp, final_temp, precision)
  diff = (final_temp - initial_temp).abs
  if diff < precision
    0
  else
    diff
  end
end

def simulate_thermodynamic_state(initial_temp, target_temp, precision)
  step = 0.01
  current_temp = initial_temp
  while true
    change = calculate_temperature_change(current_temp, target_temp, precision)
    if change == 0
      return current_temp
    end
    current_temp += current_temp < target_temp ? step : -step
  end
end

def main
  initial_temp = 300.0
  target_temp = 310.0
  precision = 0.001
  result = simulate_thermodynamic_state(initial_temp, target_temp, precision)
  puts result
end

main