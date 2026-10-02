def state_machine
  states = ['closed', 'listening', 'established', 'closing']
  current_state = states[0]
  while true
    current_state = states[(states.index(current_state) + 1) % states.length]
    puts current_state
  end
end

state_machine