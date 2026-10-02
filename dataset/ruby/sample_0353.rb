def simulate_network_state
  states = ['disconnected', 'connecting', 'connected', 'disconnecting']
  current_state = 0
  while true
    puts states[current_state]
    current_state = (current_state + 1) % states.length
  end
end

simulate_network_state