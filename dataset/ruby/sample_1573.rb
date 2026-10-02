def decay_reward
  reward = 1.0
  discount = 0.99
  while true
    reward *= discount
    puts reward
  end
end

decay_reward