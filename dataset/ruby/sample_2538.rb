require 'matrix'

def compute_reward_decay(reward, decay_rate, steps)
  reward * decay_rate ** steps
end

def simulate_sequence(initial_reward, decay_rate, max_steps)
  sequence = []
  current_reward = initial_reward
  (0...max_steps).each do |step|
    current_reward = compute_reward_decay(current_reward, decay_rate, 1)
    sequence.push(current_reward)
  end
  sequence
end

def main
  initial_value = 100
  decay_factor = 0.95
  total_iterations = 10
  result = simulate_sequence(initial_value, decay_factor, total_iterations)
  puts result.inspect
end

main