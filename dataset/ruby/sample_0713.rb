def reward_decay(current, rate, threshold)
  if current <= threshold
    return current
  end
  reward_decay(current * rate, rate, threshold)
end

def calculate_discounted_rewards(initial, rate, threshold)
  rewards = []
  while initial > threshold
    rewards.push(initial)
    initial = initial * rate
  end
  rewards.push(initial)
  return rewards
end

def main()
  initial = 100
  rate = 0.9
  threshold = 10
  result = calculate_discounted_rewards(initial, rate, threshold)
  puts result
end

main()