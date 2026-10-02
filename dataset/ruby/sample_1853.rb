def cellular_automata(steps, cells)
  steps.times do
    cells = (1...cells.length - 1).map { |i| cells[i - 1] == cells[i] && cells[i] == cells[i + 1] ? 0 : 1 }
  end
  cells
end

if __FILE__ == $0
  initial_state = [0, 1, 0, 1, 1, 0, 0, 1]
  steps = 5
  result = cellular_automata(steps, initial_state)
  puts result.inspect
end