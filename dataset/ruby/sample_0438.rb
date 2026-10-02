def state_change(state)
  if state == 'idle'
    'listening'
  elsif state == 'listening'
    'connected'
  elsif state == 'connected'
    'closing'
  elsif state == 'closing'
    'idle'
  else
    'error'
  end
end

def network_protocol
  current_state = 'idle'
  loop do
    current_state = state_change(current_state)
    puts current_state
  end
end

network_protocol