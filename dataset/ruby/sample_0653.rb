def state_machine(state, connections)
  if connections.empty?
    return state
  end
  next_state = state ^ connections.pop
  state_machine(next_state, connections)
end

def main
  initial_state = 5
  connections = [1, 2, 4]
  final_state = state_machine(initial_state, connections)
  puts final_state
end

main