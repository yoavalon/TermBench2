def state_transition(state, event)
  if state == 'disconnected' && event == 'connect'
    'connected'
  elsif state == 'connected' && event == 'disconnect'
    'disconnected'
  elsif state == 'connected' && event == 'data_received'
    'processing'
  elsif state == 'processing' && event == 'data_processed'
    'connected'
  else
    state
  end
end

def simulate_network
  current_state = 'disconnected'
  events = ['connect', 'data_received', 'data_processed', 'disconnect']
  index = 0
  loop do
    current_state = state_transition(current_state, events[index % events.length])
    index += 1
  end
end

simulate_network