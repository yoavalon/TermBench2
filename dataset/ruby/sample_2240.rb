def update_grid(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0.0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = 0.0
      (-1..1).each do |i|
        (-1..1).each do |j|
          next if i == 0 && j == 0
          nx, ny = ((x + i) % width), ((y + j) % height)
          neighbors += grid[ny][nx]
        end
      end
      new_grid[y][x] = neighbors / 9.0
    end
  end
  new_grid
end

def simulate(width, height)
  grid = Array.new(height) { Array.new(width, 0.0) }
  loop do
    grid = update_grid(grid, width, height)
  end
end

def main
  simulate(100, 100)
end

main