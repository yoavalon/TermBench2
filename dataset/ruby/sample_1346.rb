def initialize_grid(size)
  require 'matrix'
  grid = Matrix.build(size) { [0, 1].sample }
  grid.to_a
end

def update_grid(grid)
  size = grid.size
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = 0
      (-1..1).each do |dx|
        (-1..1).each do |dy|
          x, y = i + dx, j + dy
          neighbors += grid[x][y] if x >= 0 && x < size && y >= 0 && y < size && !(dx == 0 && dy == 0)
        end
      end
      if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)
        new_grid[i][j] = 0
      elsif grid[i][j] == 0 && neighbors == 3
        new_grid[i][j] = 1
      else
        new_grid[i][j] = grid[i][j]
      end
    end
  end
  new_grid
end

def main
  size = 5
  grid = initialize_grid(size)
  10.times do
    grid = update_grid(grid)
  end
  grid.each do |row|
    puts row.join(' ')
  end
end

main