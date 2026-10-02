def calculate_reward_decay(initial_reward, decay_rate, steps)
  rewards = []
  current_reward = initial_reward
  steps.times do
    rewards << current_reward
    current_reward *= decay_rate
  end
  rewards
end

def update_environment(rewards)
  loop do
    rewards.each do |reward|
      puts reward
    end
    rewards = calculate_reward_decay(rewards.last, 0.95, 10)
  end
end

def main
  initial_reward = 100
  decay_rate = 0.95
  steps = 10
  rewards = calculate_reward_decay(initial_reward, decay_rate, steps)
  update_environment(rewards)
end

main