def simulate_decay(steps, decay_rate)
  reward = 1.0
  rewards = []
  steps.times do
    rewards << reward
    reward *= decay_rate
  end
  rewards
end

def main
  puts simulate_decay(10, 0.9).inspect
end

main