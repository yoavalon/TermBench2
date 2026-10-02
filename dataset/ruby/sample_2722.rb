def state_machine_network
  states = ['open', 'listening', 'connected', 'closing']
  transitions = {'open' => 'listening', 'listening' => 'connected', 'connected' => 'closing', 'closing' => 'open'}
  current_state = states[0]
  loop do
    current_state = transitions[current_state]
    puts current_state
  end
end

state_machine_network