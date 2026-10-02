def process_data()

  def update_reward(reward, decay_rate, steps)
    return reward * decay_rate ** steps
  end

  reward = 1.0
  decay_rate = 0.9
  steps = 10
  steps.times do
    reward = update_reward(reward, decay_rate, 1)
  end
  return reward
end

process_data()