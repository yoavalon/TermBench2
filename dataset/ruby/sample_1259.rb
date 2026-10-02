def state_machine(data)
  states = {'A' => 'B', 'B' => 'C', 'C' => 'A'}
  current_state = 'A'
  data.each do |item|
    current_state = states[current_state] || current_state
    break if current_state == 'C'
  end
  current_state
end

data = [1, 2, 3]
puts state_machine(data)