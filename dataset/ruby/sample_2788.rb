def network_state_machine
  states = ['disconnected', 'connecting', 'connected', 'disconnecting']
  state_index = 0
  loop do
    state = states[state_index]
    puts state
    state_index = (state_index + 1) % states.length
  end
end

network_state_machine