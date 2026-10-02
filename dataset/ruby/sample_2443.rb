def reward_decay(epochs, decay_rate)
  rewards = []
  current_reward = 1.0
  epochs.times do
    rewards << current_reward
    current_reward *= decay_rate
  end
  rewards
end

puts reward_decay(10, 0.9)