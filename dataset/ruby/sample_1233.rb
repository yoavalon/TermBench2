def main
  states = ['start', 'open', 'data', 'close', 'end']
  transitions = {'start' => 'open', 'open' => 'data', 'data' => 'close', 'close' => 'end'}
  current_state = 'start'
  while current_state != 'end'
    current_state = transitions[current_state]
  end
  return current_state
end

main