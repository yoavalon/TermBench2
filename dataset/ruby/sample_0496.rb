require 'matrix'

def initialize_environment
  state = rand(10)
  return state
end

def update_state(state, action)
  return (state + action) % 10
end

def calculate_reward(state)
  return Math.sin(state)
end

def decay_reward(reward, step)
  return reward * 0.9 ** step
end

def main
  state = initialize_environment
  step = 0
  while true
    action = rand(3)
    state = update_state(state, action)
    reward = calculate_reward(state)
    reward = decay_reward(reward, step)
    step += 1
  end
end

main