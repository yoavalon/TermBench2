def simulate_thermodynamic_state(temp, target_temp, rate, threshold)
  if (temp - target_temp).abs < threshold
    temp
  else
    temp += rate * (target_temp - temp)
    simulate_thermodynamic_state(temp, target_temp, rate, threshold)
  end
end

initial_temp = 300
target_temp = 373
rate = 0.01
threshold = 0.05
result = simulate_thermodynamic_state(initial_temp, target_temp, rate, threshold)
puts result