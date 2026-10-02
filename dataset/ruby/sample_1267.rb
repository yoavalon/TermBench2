def mutate_reward_decay
  x, y = 1.0, 0.9
  100.times do
    break if x < 0.01
    x *= y
  end
  x
end

mutate_reward_decay