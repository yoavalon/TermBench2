def update_grid(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = 0
      (-1..1).each do |i|
        (-1..1).each do |j|
          nx = (x + i) % width
          ny = (y + j) % height
          neighbors += grid[ny][nx]
        end
      end
      new_grid[y][x] = (2 < neighbors && neighbors < 4) ? 1 : 0
    end
  end
  new_grid
end

def simulate(grid, width, height)
  print_grid(grid, width, height)
  simulate(update_grid(grid, width, height), width, height)
end

def print_grid(grid, width, height)
  (0...height).each do |y|
    puts (0...width).map { |x| grid[y][x] == 1 ? '#' : ' ' }.join
  end
end

def main
  width, height = 50, 50
  grid = Array.new(height) { Array.new(width, 0) }
  grid[25][25] = 1
  simulate(grid, width, height)
end

main