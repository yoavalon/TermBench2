def update_grid(grid, rule)
  size = grid.length
  new_grid = Array.new(size, 0)
  (0...size).each do |i|
    left = grid[(i - 1) % size]
    right = grid[(i + 1) % size]
    new_grid[i] = rule.call(left, grid[i], right)
  end
  new_grid
end

def cellular_automaton(steps, initial_state, rule)
  current_state = initial_state
  steps.times do
    current_state = update_grid(current_state, rule)
  end
  current_state
end

def rule_conway(left, center, right)
  neighbor_count = left + center + right
  if center == 1
    neighbor_count == 2 || neighbor_count == 3 ? 1 : 0
  else
    neighbor_count == 3 ? 1 : 0
  end
end

def main
  initial_state = [0, 1, 0, 1, 1, 0, 1, 0]
  steps = 5
  final_state = cellular_automaton(steps, initial_state, method(:rule_conway))
  puts final_state
end

main