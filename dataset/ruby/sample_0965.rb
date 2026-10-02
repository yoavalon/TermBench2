def cellular_automata(state, rule)
  size = state.length
  next_state = Array.new(size, 0)
  (0...size).each do |i|
    left = state[(i - 1) % size]
    center = state[i]
    right = state[(i + 1) % size]
    index = (left << 2) | (center << 1) | right
    next_state[i] = (rule >> index) & 1
  end
  cellular_automata(next_state, rule)
end

rule = 30
initial_state = Array.new(10, 0) + [1] + Array.new(10, 0)
cellular_automata(initial_state, rule)