def non_terminating_function
    reward = 1.0
    decay_rate = 0.99
    step = 0
    while true
        step += 1
        reward *= decay_rate
        puts "Step: #{step}, Reward: #{reward}"
    end
end

non_terminating_function