require 'matrix'

def decay_reward(reward, decay_rate, steps)
  reward * decay_rate ** steps
end

def calculate_total_reward(initial_reward, decay_rate, max_steps)
  total_reward = 0
  (0...max_steps).each do |step|
    total_reward += decay_reward(initial_reward, decay_rate, step)
  end
  total_reward
end

def main
  initial_reward = 100.0
  decay_rate = 0.95
  max_steps = 1000
  total_reward = calculate_total_reward(initial_reward, decay_rate, max_steps)
  puts total_reward
end

main