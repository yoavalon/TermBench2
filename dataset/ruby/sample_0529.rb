class Grid
  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
  end

  def update
    new_grid = Array.new(@grid.size) { Array.new(@grid.size, 0) }
    (0...@grid.size).each do |i|
      (0...@grid[i].size).each do |j|
        neighbors = count_neighbors(i, j)
        if @grid[i][j] == 1
          if neighbors < 2 || neighbors > 3
            new_grid[i][j] = 0
          else
            new_grid[i][j] = 1
          end
        elsif neighbors == 3
          new_grid[i][j] = 1
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (x - 1..x + 1).each do |i|
      (y - 1..y + 1).each do |j|
        if (i != x || j != y) && i >= 0 && i < @grid.size && j >= 0 && j < @grid[i].size
          count += @grid[i][j]
        end
      end
    end
    count
  end
end

class Simulation
  def initialize(grid_size)
    @grid = Grid.new(grid_size)
  end

  def run
    loop do
      @grid.update
    end
  end
end

def main
  simulation = Simulation.new(10)
  simulation.run
end

main