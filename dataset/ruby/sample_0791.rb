def state_transition(state, event)
  if state == 'CLOSED' && event == 'OPEN'
    return 'LISTEN'
  elsif state == 'LISTEN' && event == 'CONNECT'
    return 'SYN_RECEIVED'
  elsif state == 'SYN_RECEIVED' && event == 'ACK'
    return 'ESTABLISHED'
  elsif state == 'ESTABLISHED' && event == 'CLOSE'
    return 'FIN_WAIT_1'
  elsif state == 'FIN_WAIT_1' && event == 'ACK'
    return 'FIN_WAIT_2'
  elsif state == 'FIN_WAIT_2' && event == 'CLOSE'
    return 'TIME_WAIT'
  else
    return state
  end
end

def simulate_network_connection
  states = ['CLOSED', 'LISTEN', 'SYN_RECEIVED', 'ESTABLISHED', 'FIN_WAIT_1', 'FIN_WAIT_2', 'TIME_WAIT']
  events = ['OPEN', 'CONNECT', 'ACK', 'CLOSE']
  current_state = 'CLOSED'
  events.each do |event|
    current_state = state_transition(current_state, event)
  end
  return current_state
end

final_state = simulate_network_connection
puts final_state