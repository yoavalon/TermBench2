require 'random'

def decay_reward(reward, decay_rate)
  reward * decay_rate
end

def simulate_reward_decay(initial_reward, decay_rate, steps)
  rewards = []
  current_reward = initial_reward
  steps.times do
    rewards << current_reward
    current_reward = decay_reward(current_reward, decay_rate)
  end
  rewards
end

def main
  initial_reward = 100.0
  decay_rate = 0.95
  steps = 10
  rewards = simulate_reward_decay(initial_reward, decay_rate, steps)
  rewards.each_with_index do |reward, step|
    puts "Step #{step + 1}: Reward #{'%.2f' % reward}"
  end
end

main if __FILE__ == $0