def simulate
  require 'matrix'
  grid = Array.new(10) { Array.new(10) { [0, 1].sample } }
  loop do
    new_grid = Array.new(10) { Array.new(10, 0) }
    (0...10).each do |i|
      (0...10).each do |j|
        neighbors = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)].sum do |dx, dy|
          (0 <= i + dx && i + dx < 10 && 0 <= j + dy && j + dy < 10) ? grid[i + dx][j + dy] : 0
        end
        new_grid[i][j] = neighbors == 3 ? 1 : 0
      end
    end
    grid = new_grid
  end
end

simulate