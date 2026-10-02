def state_transition(state, input)
  if state == 'idle' && input == 'connect'
    'connecting'
  elsif state == 'connecting' && input == 'acknowledged'
    'connected'
  elsif state == 'connected' && input == 'disconnect'
    'disconnecting'
  elsif state == 'disconnecting' && input == 'disconnected'
    'idle'
  else
    state
  end
end

def process_inputs
  current_state = 'idle'
  inputs = ['connect', 'acknowledged', 'disconnect', 'disconnected']
  loop do
    inputs.each do |input|
      current_state = state_transition(current_state, input)
    end
  end
end

def main
  process_inputs
end

main