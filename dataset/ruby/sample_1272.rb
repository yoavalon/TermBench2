def network_state_machine
  states = ['idle', 'connected', 'failed']
  transitions = {'idle' => 'connected', 'connected' => 'failed', 'failed' => 'idle'}
  state = 'idle'
  3.times do
    state = transitions[state]
  end
  return state
end

network_state_machine()