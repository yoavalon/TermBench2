require 'matrix'

class AutomataGrid
  def initialize(size, density)
    @grid = Matrix.build(size, size) { rand < density ? 1 : 0 }
    @size = size
  end

  def apply_rules
    new_grid = @grid.dup
    (1...@size - 1).each do |i|
      (1...@size - 1).each do |j|
        neighbors = @grid.minor([i-1, i, i+1], [j-1, j, j+1]).sum - @grid[i, j]
        if @grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)
          new_grid[i, j] = 0
        elsif @grid[i, j] == 0 && neighbors == 3
          new_grid[i, j] = 1
        end
      end
    end
    @grid = new_grid
  end

  def set_boundary_conditions
    @grid.column(0).assign(@grid.column(@size - 2))
    @grid.column(@size - 1).assign(@grid.column(1))
    @grid.row(0).assign(@grid.row(@size - 2))
    @grid.row(@size - 1).assign(@grid.row(1))
  end
end

class Simulation
  def initialize(grid, steps)
    @grid = grid
    @steps = steps
  end

  def run
    @steps.times do
      @grid.apply_rules
      @grid.set_boundary_conditions
    end
  end
end

def main
  size = 10
  density = 0.3
  steps = 50
  grid = AutomataGrid.new(size, density)
  simulation = Simulation.new(grid, steps)
  simulation.run
end

main if __FILE__ == $0