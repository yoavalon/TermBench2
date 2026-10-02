def reward_decay
    reward = 1.0
    decay_rate = 0.9
    iterations = 10
    iterations.times do
        reward *= decay_rate
    end
    return reward
end

reward_decay()