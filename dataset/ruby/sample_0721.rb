def decay_reward(reward, factor, threshold)
  if reward < threshold
    return 0
  end
  return reward * factor
end

def compute_reward(initial, factor, steps, threshold)
  reward = initial
  steps.times do
    reward = decay_reward(reward, factor, threshold)
  end
  return reward
end

def main
  initial_reward = 100
  decay_factor = 0.9
  steps = 10
  threshold = 10
  final_reward = compute_reward(initial_reward, decay_factor, steps, threshold)
  puts final_reward
end

main