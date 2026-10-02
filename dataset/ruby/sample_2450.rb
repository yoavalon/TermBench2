def simulate_cells(rows, cols, steps)
  grid = Array.new(rows) { Array.new(cols, 0) }
  steps.times do
    new_grid = Array.new(rows) { Array.new(cols, 0) }
    rows.times do |i|
      cols.times do |j|
        neighbors = 0
        (-1..1).each do |dx|
          (-1..1).each do |dy|
            ni, nj = i + dx, j + dy
            neighbors += grid[ni][nj] if ni >= 0 && ni < rows && nj >= 0 && nj < cols && !(ni == i && nj == j)
          end
        end
        new_grid[i][j] = 1 if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)
      end
    end
    grid = new_grid
  end
  grid
end

simulate_cells(10, 10, 5)