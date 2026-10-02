require 'random'

def simulate_episode(decay_factor)
  total_reward = 0.0
  current_reward = 1.0
  step = 0
  loop do
    step += 1
    total_reward += current_reward
    current_reward *= decay_factor
    yield total_reward, step
  end
end

def main
  decay_factor = 0.95
  simulate_episode(decay_factor) do |total_reward, step|
    puts "Step #{step}: Total Reward #{total_reward}"
  end
end

main