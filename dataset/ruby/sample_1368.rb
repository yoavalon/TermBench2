def compute_reward_decay(initial_reward, decay_rate, time_steps)
  reward = initial_reward
  time_steps.times do
    reward *= decay_rate
  end
  reward
end

def simulate_data_mutation(initial_data, decay_rate, steps)
  mutated_data = []
  initial_data.each do |data_point|
    reward = compute_reward_decay(data_point, decay_rate, steps)
    mutated_data << reward
  end
  mutated_data
end

def main
  data = [100, 200, 300, 400, 500]
  rate = 0.95
  steps = 10
  result = simulate_data_mutation(data, rate, steps)
  puts result
end

main