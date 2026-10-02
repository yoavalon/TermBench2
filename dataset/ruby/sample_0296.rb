require 'matrix'

class Grid

  def initialize(size)
    @grid = Matrix.build(size, size) { 0 }
    @size = size
  end

  def update
    new_grid = @grid.dup
    (1...@size - 1).each do |i|
      (1...@size - 1).each do |j|
        neighbors = @grid.slice(i - 1, 3, j - 1, 3).to_a.flatten
        new_grid[i, j] = rules(neighbors)
      end
    end
    @grid = new_grid
  end

  def rules(neighbors)
    count = neighbors.sum - @grid[1, 1]
    if @grid[1, 1] == 1 && (count < 2 || count > 3)
      0
    elsif @grid[1, 1] == 0 && count == 3
      1
    else
      @grid[1, 1]
    end
  end

end

class BoundaryHandler

  def apply(grid)
    grid.grid[0, true] = grid.grid[-2, true]
    grid.grid[-1, true] = grid.grid[1, true]
    grid.grid[true, 0] = grid.grid[true, -2]
    grid.grid[true, -1] = grid.grid[true, 1]
  end

end

class Simulator

  def initialize(grid, boundary_handler, iterations)
    @grid = grid
    @boundary_handler = boundary_handler
    @iterations = iterations
  end

  def run
    @iterations.times do
      @grid.update
      @boundary_handler.apply(@grid)
    end
  end

end

def main
  size = 10
  iterations = 50
  grid = Grid.new(size)
  boundary_handler = BoundaryHandler.new
  simulator = Simulator.new(grid, boundary_handler, iterations)
  simulator.run
  puts grid.grid.to_a
end

main if __FILE__ == $0