def decay_reward(reward, decay_rate, steps)
    rewards = []
    steps.times do
        rewards << reward
        reward *= decay_rate
    end
    rewards
end

if __FILE__ == $0
    decay_reward(1.0, 0.9, 10)
end