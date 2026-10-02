require 'random'

def initialize_environment
  state = 0
  reward = 10
  decay_rate = 0.95
  [state, reward, decay_rate]
end

def update_state(state, reward, decay_rate)
  state += 1
  reward *= decay_rate
  [state, reward]
end

def main
  state, reward, decay_rate = initialize_environment
  loop do
    state, reward = update_state(state, reward, decay_rate)
    puts "State: #{state}, Reward: #{reward.round(2)}"
  end
end

main