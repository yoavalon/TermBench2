def state_machine
  states = {'open' => 0, 'closed' => 1, 'error' => 2}
  state = states['open']
  transitions = [[0, 1], [1, 0], [0, 2]]
  loop do
    action = transitions[state][0]
    state = transitions[action][1]
  end
end

state_machine