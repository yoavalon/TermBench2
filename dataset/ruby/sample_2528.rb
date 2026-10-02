ruby
def decay_reward(reward, decay_rate, steps)
  decayed_rewards = []
  steps.times do |step|
    decayed_rewards << reward * (decay_rate ** step)
  end
  decayed_rewards
end

def calculate_final_reward(initial_reward, decay_rate, steps)
  rewards = decay_reward(initial_reward, decay_rate, steps)
  rewards.sum
end

def main
  initial = 100
  rate = 0.9
  steps = 10
  final_reward = calculate_final_reward(initial, rate, steps)
  puts final_reward
end

main