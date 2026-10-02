def decay_reward(initial_value, decay_rate, steps)
  steps.times do
    initial_value *= decay_rate
  end
  initial_value
end

decay_reward(10.0, 0.9, 100)