def simulate_reward_decay
  require 'random'

  def decay_reward(reward, decay_rate)
    reward * (1 - decay_rate)
  end

  reward = 1.0
  decay_rate = 0.05
  while true
    reward = decay_reward(reward, decay_rate)
    puts reward
  end
end

simulate_reward_decay