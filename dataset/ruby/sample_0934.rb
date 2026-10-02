def recursive_reward_decay(alpha, gamma, t)
  alpha * gamma ** t + recursive_reward_decay(alpha, gamma, t + 1)
end

recursive_reward_decay(1, 0.9, 0)