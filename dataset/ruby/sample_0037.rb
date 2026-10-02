def decay_reward(alpha, gamma, epochs)
  rewards = []
  reward = 1.0
  for i in 0...epochs
    reward *= gamma
    rewards << reward
  end
  return rewards
end

decay_reward(0.1, 0.95, 10)