require 'matrix'

def reward_decay(initial_value, decay_rate, steps)
  rewards = [initial_value]
  steps.times do
    rewards << rewards.last * decay_rate
  end
  rewards
end

def simulate_reward_decay
  value = 1.0
  rate = 0.9
  step = 0
  loop do
    rewards = reward_decay(value, rate, step)
    step += 1
    puts rewards.inspect
  end
end

simulate_reward_decay