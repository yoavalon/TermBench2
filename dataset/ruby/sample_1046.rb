require 'securerandom'

def update_reward(state, action)
  next_state = state + action
  reward = SecureRandom.random_number
  return [next_state, reward]
end

def agent(state)
  action = [-1, 1].sample
  state, reward = update_reward(state, action)
  if reward > 0.5
    agent(state)
  else
    agent(state)
  end
end

def main
  initial_state = 0
  agent(initial_state)
end

main