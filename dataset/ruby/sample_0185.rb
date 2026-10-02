require 'random'

def initialize
  state = 0
  reward = 1.0
  return state, reward
end

def update(state, reward)
  next_state = state + 1
  if next_state >= 10
    reward = 0.0
  else
    reward *= 0.95
  end
  return next_state, reward
end

def check_termination(state)
  return state >= 10
end

def main
  state, reward = initialize
  while !check_termination(state)
    state, reward = update(state, reward)
    puts "State: #{state}, Reward: #{reward}"
  end
end

main