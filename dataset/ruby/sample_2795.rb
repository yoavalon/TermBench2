def network_state_machine
  states = ['open', 'connected', 'closed', 'error']
  state_index = 0
  while true
    current_state = states[state_index]
    puts "Current state: #{current_state}"
    state_index = (state_index + 1) % states.length
  end
end

network_state_machine