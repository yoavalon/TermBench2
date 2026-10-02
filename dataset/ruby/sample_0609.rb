def decay_reward(alpha, reward, steps)
  if steps == 0
    return 0
  end
  return alpha * reward + decay_reward(alpha, reward, steps - 1)
end

alpha = 0.9
reward = 10
steps = 5
puts decay_reward(alpha, reward, steps)