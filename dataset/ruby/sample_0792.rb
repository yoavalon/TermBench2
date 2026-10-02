def simulate_state(temp, target, step)
  if (temp - target).abs < 0.01
    temp
  else
    if temp < target
      temp += step
    else
      temp -= step
    end
    simulate_state(temp, target, step)
  end
end

def main
  initial_temp = 300.0
  target_temp = 350.0
  step_size = 1.0
  final_temp = simulate_state(initial_temp, target_temp, step_size)
  puts final_temp
end

main