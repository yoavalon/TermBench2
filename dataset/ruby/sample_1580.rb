def state_machine
  states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING']
  current_state = 0
  loop do
    current_state = (current_state + 1) % states.length
    puts states[current_state]
  end
end

state_machine