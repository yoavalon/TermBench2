def reward_decay(reward, decay_rate, steps)
  decayed_rewards = []
  (0...steps).each do |i|
    decayed_rewards << reward
    reward *= decay_rate
  end
  decayed_rewards
end

def process_data(data)
  results = {}
  data.each_with_index do |val, idx|
    results[idx] = val
  end
  results
end

def main
  initial_reward = 1.0
  decay_rate = 0.9
  steps = 10
  rewards = reward_decay(initial_reward, decay_rate, steps)
  output = process_data(rewards)
  output.each do |key, value|
    puts "Step #{key}: #{value}"
  end
end

main