require 'matrix'

def update_reward(state, action)
  if action == 0
    state * 0.95
  else
    state * 0.9
  end
end

def simulate_episodes(num_episodes, max_steps)
  rewards = []
  num_episodes.times do
    state = 1.0
    max_steps.times do
      action = rand(2)
      state = update_reward(state, action)
      break if state < 0.1
    end
    rewards << state
  end
  rewards.sum.to_f / rewards.size
end

def main
  result = simulate_episodes(100, 1000)
  puts result
end

main