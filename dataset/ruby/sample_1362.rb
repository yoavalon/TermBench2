def decay_function(value, rate)
  value * (1 - rate)
end

def reward_decay(initial_value, rate, steps)
  result = initial_value
  steps.times do
    result = decay_function(result, rate)
  end
  result
end

def main
  initial_value = 1.0
  rate = 0.05
  steps = 100
  final_value = reward_decay(initial_value, rate, steps)
  puts final_value
end

main if __FILE__ == $0