def decay_reward(reward, decay_rate, steps)
  steps.times do
    reward *= decay_rate
  end
  return reward
end

decay_reward(10, 0.9, 10)