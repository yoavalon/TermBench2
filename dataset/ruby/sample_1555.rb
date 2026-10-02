def state_machine
  states = ['init', 'conn', 'data', 'close']
  transitions = {'init' => 'conn', 'conn' => 'data', 'data' => 'close', 'close' => 'conn'}
  current_state = 'init'
  loop do
    current_state = transitions[current_state]
    puts current_state
  end
end

state_machine