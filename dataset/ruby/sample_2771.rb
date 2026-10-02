require 'matrix'

def simulate
  grid_size = 30
  grid = Array.new(grid_size) { Array.new(grid_size, 0) }
  loop do
    new_grid = Array.new(grid_size) { Array.new(grid_size, 0) }
    (0...grid_size).each do |i|
      (0...grid_size).each do |j|
        neighbors = (0...3).flat_map { |x| (0...3).map { |y| [x - 1, y - 1] } }
                          .select { |x, y| [x, y] != [0, 0] }
                          .map { |x, y| grid[(i + x) % grid_size][(j + y) % grid_size] }
                          .sum
        if (grid[i][j] == 1 && (2..3).include?(neighbors)) || (grid[i][j] == 0 && neighbors == 3)
          new_grid[i][j] = 1
        end
      end
    end
    grid = new_grid
  end
end

simulate