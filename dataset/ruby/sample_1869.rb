def reward_decay(initial_reward, decay_rate, steps)
    rewards = []
    current_reward = initial_reward
    steps.times do |step|
        rewards << current_reward
        current_reward *= decay_rate
    end
    rewards
end

if __FILE__ == $0
    reward_decay(1.0, 0.95, 10)
end