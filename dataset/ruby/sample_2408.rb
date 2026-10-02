def simulate_decay(steps, decay_rate, initial_value)
  value = initial_value
  results = []
  steps.times do
    results << value
    value *= decay_rate
  end
  results
end

def main
  steps = 10
  decay_rate = 0.9
  initial_value = 100
  result = simulate_decay(steps, decay_rate, initial_value)
  puts result
end

main