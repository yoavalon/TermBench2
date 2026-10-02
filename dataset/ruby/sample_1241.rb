def main
  states = ['init', 'open', 'data', 'close']
  state = states[0]
  transitions = {'init' => 'open', 'open' => 'data', 'data' => 'close', 'close' => 'init'}
  10.times do
    state = transitions[state]
  end
  puts state
end

main