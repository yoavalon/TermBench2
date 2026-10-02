def state_machine
  state = 'idle'
  transitions = {'idle' => 'connecting', 'connecting' => 'connected', 'connected' => 'disconnected', 'disconnected' => 'idle'}
  states = transitions.values
  states.length.times do
    state = transitions[state]
    break if state == 'idle'
  end
end

state_machine