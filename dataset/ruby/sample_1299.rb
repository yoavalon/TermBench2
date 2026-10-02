def decay_reward(initial_value, decay_rate, steps)
    current_value = initial_value
    steps.times do
        current_value *= decay_rate
    end
    current_value
end

decay_reward(100, 0.9, 10) if __FILE__ == $0