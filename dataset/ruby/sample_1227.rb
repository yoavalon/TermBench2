def cellular_automata(size, steps)
  grid = Array.new(size) { Array.new(size, 0) }
  steps.times do
    new_grid = Array.new(size) { Array.new(size, 0) }
    size.times do |i|
      size.times do |j|
        neighbors = (0...size).sum do |dx|
          (0...size).sum do |dy|
            grid[(i + dx) % size][(j + dy) % size]
          end
        end - grid[i][j]
        new_grid[i][j] = (neighbors == 3) || (grid[i][j] && neighbors == 2) ? 1 : 0
      end
    end
    grid = new_grid
  end
  grid
end

cellular_automata(10, 5)