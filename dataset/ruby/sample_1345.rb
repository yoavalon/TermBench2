require 'random'

def initialize_state
  state = { 'position' => 0, 'reward' => 1.0 }
  state
end

def update_state(state)
  state['position'] += [-1, 1].sample
  state['reward'] *= 0.99
  state
end

def should_terminate(state)
  abs(state['position']) > 10 || state['reward'] < 0.1
end

def main
  state = initialize_state
  while !should_terminate(state)
    state = update_state(state)
  end
  puts state
end

main if __FILE__ == $0