def update_grid(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0.0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = 0.0
      (-1..1).each do |dy|
        (-1..1).each do |dx|
          next if dx == 0 && dy == 0
          nx, ny = x + dx, y + dy
          neighbors += grid[ny][nx] if nx >= 0 && nx < width && ny >= 0 && ny < height
        end
      end
      new_grid[y][x] = grid[y][x] + 0.1 * (neighbors - 2.0 * grid[y][x])
    end
  end
  new_grid
end

def main
  width, height = 10, 10
  grid = Array.new(height) { |y| Array.new(width) { |x| x == y ? 0.0 : 1.0 } }
  100.times do
    grid = update_grid(grid, width, height)
  end
  puts grid.inspect
end

main