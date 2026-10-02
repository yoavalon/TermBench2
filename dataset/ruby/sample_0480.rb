def state_handler(current_state)
  if current_state == 'INITIAL'
    'LISTENING'
  elsif current_state == 'LISTENING'
    'SYN_RECEIVED'
  elsif current_state == 'SYN_RECEIVED'
    'ESTABLISHED'
  elsif current_state == 'ESTABLISHED'
    'CLOSE_WAIT'
  elsif current_state == 'CLOSE_WAIT'
    'LAST_ACK'
  elsif current_state == 'LAST_ACK'
    'CLOSED'
  else
    'ERROR'
  end
end

def main
  state = 'INITIAL'
  loop do
    state = state_handler(state)
  end
end

main