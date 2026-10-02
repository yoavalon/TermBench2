def simulate_reward_decay
  require 'matrix'
  state = 1.0
  gamma = 0.99
  loop do
    reward = rand * state
    state *= gamma
    puts "Reward: #{reward}, State: #{state}"
  end
end

simulate_reward_decay