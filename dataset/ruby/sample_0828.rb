require 'matrix'

def initialize_environment
  state = rand(100)
  reward = 100.0
  decay_rate = 0.99
  return [state, reward, decay_rate]
end

def update_state(state, action)
  if action == 0
    state += 1
  else
    state -= 1
  end
  return state
end

def calculate_reward(state, reward, decay_rate, steps)
  reward *= decay_rate ** steps
  return reward
end

def terminate_condition(state)
  return state == 50
end

def agent_action(state)
  if state < 50
    return 0
  else
    return 1
  end
end

def main
  state, reward, decay_rate = initialize_environment
  steps = 0
  while !terminate_condition(state)
    action = agent_action(state)
    state = update_state(state, action)
    steps += 1
    reward = calculate_reward(state, reward, decay_rate, steps)
  end
  puts "Final State: #{state}, Reward: #{'%.2f' % reward}, Steps: #{steps}"
end

main