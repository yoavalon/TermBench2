def decay_function(current_value, decay_rate)
  current_value * (1 - decay_rate)
end

def termination_analysis(initial_value, threshold, decay_rate)
  value = initial_value
  count = 0
  while value > threshold
    value = decay_function(value, decay_rate)
    count += 1
  end
  count
end

def main
  initial_value = 1.0
  threshold = 0.01
  decay_rate = 0.1
  result = termination_analysis(initial_value, threshold, decay_rate)
  puts result
end

main