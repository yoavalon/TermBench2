def compute_decay(reward, rate, steps)
  decayed_rewards = []
  (0...steps).each do |step|
    decayed_reward = reward * rate ** step
    decayed_rewards << decayed_reward
    break if decayed_reward < 0.01
  end
  decayed_rewards
end

def analyze_data(data)
  total = data.sum
  average = data.length > 0 ? total / data.length : 0
  [total, average]
end

def main
  initial_reward = 1.0
  decay_rate = 0.95
  max_steps = 1000
  rewards = compute_decay(initial_reward, decay_rate, max_steps)
  total, average = analyze_data(rewards)
  puts "Total Reward: #{total}, Average Reward: #{average}"
end

main