require 'matrix'

class Grid
  attr_accessor :size, :grid

  def initialize(size)
    @size = size
    @grid = Array.new(size) { Array.new(size, 0) }
  end

  def update
    new_grid = Array.new(size) { Array.new(size, 0) }
    (0...size).each do |i|
      (0...size).each do |j|
        neighbors = count_neighbors(i, j)
        if @grid[i][j] == 1
          new_grid[i][j] = neighbors == 2 || neighbors == 3 ? 1 : 0
        else
          new_grid[i][j] = neighbors == 3 ? 1 : 0
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (max(0, x - 1)...min(size, x + 2)).each do |i|
      (max(0, y - 1)...min(size, y + 2)).each do |j|
        count += @grid[i][j] unless [i, j] == [x, y]
      end
    end
    count
  end
end

class Simulation
  attr_accessor :grid

  def initialize(grid_size)
    @grid = Grid.new(grid_size)
    populate_grid
  end

  def populate_grid
    (0...@grid.size).each do |i|
      (0...@grid.size).each do |j|
        @grid.grid[i][j] = [0, 1].sample
      end
    end
  end

  def run
    loop do
      @grid.update
    end
  end
end

def main
  sim = Simulation.new(10)
  sim.run
end

main