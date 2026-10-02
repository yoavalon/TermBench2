def decay_function(value, rate, precision)
  (value * (1 - rate)).round(precision)
end

def simulate_decay(initial_value, decay_rate, precision, steps)
  values = [initial_value]
  steps.times do
    current_value = values[-1]
    new_value = decay_function(current_value, decay_rate, precision)
    values.push(new_value)
  end
  values
end

def main
  initial_value = 1.0
  decay_rate = 0.1
  precision = 4
  steps = 10
  result = simulate_decay(initial_value, decay_rate, precision, steps)
  puts result
end

main if __FILE__ == $0