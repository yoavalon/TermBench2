def sequence_reward_decay(steps, decay_rate)
    rewards = []
    reward = 1.0
    steps.times do
        rewards << reward
        reward *= decay_rate
    end
    return rewards
end

steps = 10
decay_rate = 0.9
result = sequence_reward_decay(steps, decay_rate)
puts result