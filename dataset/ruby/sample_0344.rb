def simulate_reward_decay
  state = 0
  reward = 1.0
  discount = 0.99
  while true
    state += 1
    reward *= discount
    puts "State: #{state}, Reward: #{reward}"
  end
end

simulate_reward_decay