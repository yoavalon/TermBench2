require 'random'

def calculate_reward(state, action)
  reward = state + action - rand(0..10)
  [0, reward].max
end

def update_state(state, action)
  new_state = state + action - rand(-5..5)
  [0, new_state].max
end

def main
  state = rand(10..50)
  action = rand(1..5)
  reward = calculate_reward(state, action)
  state = update_state(state, action)
  puts "Initial State: #{state}, Action: #{action}, Reward: #{reward}, New State: #{state}"
end

main if __FILE__ == $0