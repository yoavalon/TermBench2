def reward_decay(alpha, gamma, steps)
  reward = 1
  steps.times do
    reward *= alpha * gamma
  end
  reward
end

alpha = 0.5
gamma = 0.9
steps = 10
result = reward_decay(alpha, gamma, steps)
puts result