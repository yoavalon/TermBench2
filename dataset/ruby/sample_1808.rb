require 'securerandom'

def simulate_reward_decay(steps, decay_rate)
  rewards = [SecureRandom.random_number]
  (steps - 1).times do
    rewards << rewards.last * decay_rate
  end
  rewards
end

def main
  steps = 10
  decay_rate = 0.9
  result = simulate_reward_decay(steps, decay_rate)
  puts result.inspect
end

main