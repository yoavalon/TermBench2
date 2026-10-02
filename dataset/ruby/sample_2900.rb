def initialize_grid(size)
  require 'random'
  Array.new(size) { Array.new(size) { [0, 1].sample } }
end

def update_grid(grid)
  size = grid.size
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = (0...size).sum do |dx|
        (0...size).sum do |dy|
          grid[(i + dx) % size][(j + dy) % size] if [dx, dy] != [0, 0]
        end
      end
      new_grid[i][j] = neighbors == 3 ? 1 : neighbors == 2 ? grid[i][j] : 0
    end
  end
  new_grid
end

def main
  grid = initialize_grid(10)
  loop do
    grid = update_grid(grid)
    grid.each do |row|
      puts row.map { |cell| cell == 1 ? 'O' : ' ' }.join
    end
    puts
  end
end

main