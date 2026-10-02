require 'random'

def calculate_reward_decay(initial_reward, decay_rate, step)
  initial_reward * decay_rate ** step
end

def simulate_episode(initial_reward, decay_rate, max_steps)
  total_reward = 0
  step = 0
  while step < max_steps
    reward = calculate_reward_decay(initial_reward, decay_rate, step)
    total_reward += reward
    step += 1
  end
  total_reward
end

def main
  initial_reward = 1.0
  decay_rate = 0.9
  max_steps = 10
  result = simulate_episode(initial_reward, decay_rate, max_steps)
  puts result
end

main