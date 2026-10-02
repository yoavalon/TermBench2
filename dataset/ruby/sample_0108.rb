require 'securerandom'

def generate_reward
  SecureRandom.uniform(0.1, 1.0)
end

def update_state(state, reward, decay_rate)
  state * decay_rate + reward
end

def should_terminate(state, threshold)
  state < threshold
end

def main
  state = 1.0
  decay_rate = 0.9
  threshold = 0.1
  steps = 0
  max_steps = 100
  while steps < max_steps && !should_terminate(state, threshold)
    reward = generate_reward
    state = update_state(state, reward, decay_rate)
    steps += 1
  end
  puts "Terminated after #{steps} steps with state #{format('%.2f', state)}"
end

main