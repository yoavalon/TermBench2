require 'matrix'

class CellularAutomaton
  def initialize(size)
    @grid = Matrix.build(size, size) { rand(2) }
  end

  def update
    new_grid = @grid.dup
    (0...@grid.row_count).each do |i|
      (0...@grid.column_count).each do |j|
        neighbors = @grid[i-1, i+2, j-1, j+2]
        new_grid[i, j] = (neighbors.sum == 3) || (@grid[i, j] == 1 && neighbors.sum == 2) ? 1 : 0
      end
    end
    @grid = new_grid
  end

  def get_state
    @grid
  end
end

class FluidSimulator
  def initialize(size, steps)
    @size = size
    @steps = steps
    @ca = CellularAutomaton.new(size)
  end

  def simulate
    @steps.times do
      @ca.update
    end
  end

  def get_result
    @ca.get_state
  end
end

def main
  size = 100
  steps = 1000
  simulator = FluidSimulator.new(size, steps)
  simulator.simulate
  result = simulator.get_result
  puts result
end

main