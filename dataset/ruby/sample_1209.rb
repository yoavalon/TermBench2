ruby
def simulate_decay_reward(initial_reward, decay_rate, steps)
    rewards = [initial_reward]
    steps.times do
        current_reward = rewards.last * (1 - decay_rate)
        rewards << current_reward
    end
    rewards
end

def main
    initial_reward = 1.0
    decay_rate = 0.1
    steps = 10
    result = simulate_decay_reward(initial_reward, decay_rate, steps)
    puts result.inspect
end

main