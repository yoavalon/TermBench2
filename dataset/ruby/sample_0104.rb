require 'securerandom'

def initialize_state
  state = { 'temperature' => rand(200.0...300.0), 'pressure' => rand(1.0...10.0) }
  return state
end

def update_state(state)
  state['temperature'] += rand(-10.0...10.0)
  state['pressure'] += rand(-1.0...1.0)
  return state
end

def check_conditions(state)
  return state['temperature'] < 250 || state['pressure'] > 8
end

def simulate
  state = initialize_state
  while !check_conditions(state)
    state = update_state(state)
  end
  return state
end

def main
  result = simulate
  puts result
end

main