require 'matrix'

def calculate_reward_decay(initial_reward, decay_rate, time_steps)
  rewards = Array.new(time_steps, 0)
  rewards[0] = initial_reward
  (1...time_steps).each do |t|
    rewards[t] = rewards[t - 1] * (1 - decay_rate)
  end
  rewards
end

def simulate_terminal_condition(rewards, threshold)
  rewards.any? { |reward| reward < threshold }
end

def main
  initial_reward = 1.0
  decay_rate = 0.05
  time_steps = 20
  threshold = 0.01
  rewards = calculate_reward_decay(initial_reward, decay_rate, time_steps)
  terminal_condition = simulate_terminal_condition(rewards, threshold)
  puts 'Terminal Condition Met:', terminal_condition
end

main