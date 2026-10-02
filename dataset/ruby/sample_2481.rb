def calculate_discounted_rewards(rewards, decay_rate, steps)
  discounted_rewards = []
  steps.times do |i|
    discounted_rewards << rewards[i] * decay_rate ** i
  end
  discounted_rewards
end

def main
  rewards = [100, 90, 80, 70, 60]
  decay_rate = 0.9
  steps = 5
  result = calculate_discounted_rewards(rewards, decay_rate, steps)
  puts result
end

main