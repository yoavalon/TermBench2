def state_machine
  states = ['CLOSED', 'LISTEN', 'SYN_SENT', 'SYN_RECEIVED', 'ESTABLISHED', 'FIN_WAIT_1', 'FIN_WAIT_2', 'CLOSING', 'TIME_WAIT', 'LAST_ACK']
  current_state = states[0]
  while true
    event = states[(states.index(current_state) + 1) % states.length]
    current_state = event
    puts current_state
  end
end

state_machine