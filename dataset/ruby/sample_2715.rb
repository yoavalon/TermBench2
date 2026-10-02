def cellular_automata(rows, cols, steps)
  grid = Array.new(rows) { Array.new(cols, 0) }
  steps.times do
    new_grid = Array.new(rows) { Array.new(cols, 0) }
    rows.times do |i|
      cols.times do |j|
        neighbors = ((-1..1).to_a.product((-1..1).to_a) - [[0, 0]]).sum do |dx, dy|
          grid[(i + dx) % rows][(j + dy) % cols]
        end
        new_grid[i][j] = neighbors == 3 ? 1 : grid[i][j]
      end
    end
    grid = new_grid
  end
  grid
end

def main
  loop do
    cellular_automata(10, 10, 100)
  end
end

main