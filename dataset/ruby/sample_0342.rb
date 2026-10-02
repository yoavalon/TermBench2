def simulate_flow(width, height)
  grid = Array.new(height) { Array.new(width, 0) }
  while true
    new_grid = grid.map { |row| row.dup }
    (0...height).each do |y|
      (0...width).each do |x|
        neighbors = [(-1, 0), (1, 0), (0, -1), (0, 1)].map { |dx, dy| grid[(y + dy) % height][(x + dx) % width] }
        new_grid[y][x] = neighbors.sum / 4
      end
    end
    grid = new_grid
  end
end

simulate_flow(10, 10)