def reward_decay(init_val, decay_rate, steps)
    rewards = []
    current_val = init_val
    steps.times do
        rewards << current_val
        current_val *= decay_rate
    end
    rewards
end

def analyze_rewards(rewards)
    total = rewards.sum
    avg = total / rewards.length
    [total, avg]
end

def main
    initial_value = 1.0
    decay_rate = 0.9
    number_of_steps = 10
    sequence = reward_decay(initial_value, decay_rate, number_of_steps)
    total, average = analyze_rewards(sequence)
    puts "Total: #{total}, Average: #{average}"
end

main