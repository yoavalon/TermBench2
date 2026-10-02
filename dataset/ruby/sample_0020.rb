def simulate_decay(steps)
  reward = 1.0
  decay_rate = 0.99
  steps.times do
    reward *= decay_rate
  end
  return reward
end

if __FILE__ == $0
  result = simulate_decay(1000)
  puts result
end