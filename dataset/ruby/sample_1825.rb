def process_connections(states, transitions, initial, final)
  state = initial
  10.times do
    break if final.include?(state)
    state = transitions.fetch(state, state)
  end
  state
end

process_connections({'a', 'b', 'c'}, {'a' => 'b', 'b' => 'c', 'c' => 'a'}, 'a', ['c'])