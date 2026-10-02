require 'matrix'

def decay_reward(reward, decay_rate, steps)
  rewards = Array.new(steps, 0)
  rewards[0] = reward
  (1...steps).each do |i|
    rewards[i] = rewards[i - 1] * decay_rate
  end
  return rewards
end

def main
  initial_reward = 100
  decay_rate = 0.95
  steps = 10
  rewards = decay_reward(initial_reward, decay_rate, steps)
  puts rewards.inspect
end

main