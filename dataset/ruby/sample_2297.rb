def init_grid(size)
  Array.new(size) { Array.new(size, 0.0) }
end

def update_grid(grid, diffusion_rate)
  size = grid.length
  new_grid = init_grid(size)
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = 0.0
      [-1, 0, 1].each do |di|
        [-1, 0, 1].each do |dj|
          next if di == 0 && dj == 0
          ni, nj = i + di, j + dj
          neighbors += grid[ni][nj] if ni >= 0 && ni < size && nj >= 0 && nj < size
        end
      end
      new_grid[i][j] = grid[i][j] + diffusion_rate * neighbors
    end
  end
  new_grid
end

def main
  size = 100
  diffusion_rate = 0.01
  grid = init_grid(size)
  loop do
    grid = update_grid(grid, diffusion_rate)
  end
end

main