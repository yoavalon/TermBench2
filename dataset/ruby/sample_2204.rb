def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0.0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      total = 0.0
      [-1, 0, 1].each do |di|
        [-1, 0, 1].each do |dj|
          ni, nj = i + di, j + dj
          if ni >= 0 && ni < rows && nj >= 0 && nj < cols
            total += grid[ni][nj]
          end
        end
      end
      new_grid[i][j] = total / 9.0
    end
  end
  new_grid
end

def simulate
  grid = (0...10).map { |i| (0...10).map { |j| i.to_f + j } }
  loop do
    grid = update_grid(grid)
  end
end

simulate