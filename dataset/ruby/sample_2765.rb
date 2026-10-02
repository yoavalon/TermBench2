def cellular_automata(n)
  state = Array.new(n, 0)
  state[n / 2] = 1
  while true
    new_state = Array.new(n, 0)
    (1...n - 1).each do |i|
      new_state[i] = state[i - 1] ^ state[i + 1]
    end
    state = new_state
  end
end

cellular_automata(30)