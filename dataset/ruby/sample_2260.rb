require 'matrix'

def reward_decay(state, alpha)
  state * alpha
end

def update_state(state, action, reward)
  state + action * reward
end

def simulate_system(initial_state, alpha, action_sequence)
  state = initial_state
  loop do
    action_sequence.each do |action|
      reward = reward_decay(state, alpha)
      state = update_state(state, action, reward)
    end
  end
end

def main
  initial_state = rand
  alpha = 0.99
  action_sequence = Array.new(100) { rand(2) }
  simulate_system(initial_state, alpha, action_sequence)
end

main