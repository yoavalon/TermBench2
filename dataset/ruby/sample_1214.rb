def process
  states = ['init', 'connect', 'data_exchange', 'disconnect', 'done']
  transitions = {'init' => 'connect', 'connect' => 'data_exchange', 'data_exchange' => 'disconnect', 'disconnect' => 'done'}
  current_state = states[0]
  while current_state != states[-1]
    current_state = transitions[current_state]
  end
  puts 'Process terminated'
end

process