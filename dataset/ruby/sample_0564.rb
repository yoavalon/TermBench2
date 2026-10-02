class FluidSimulator
  def initialize(grid_size)
    @grid = Array.new(grid_size) { Array.new(grid_size, 0) }
    @size = grid_size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        new_grid[i][j] = apply_rules(i, j)
      end
    end
    @grid = new_grid
  end

  def apply_rules(x, y)
    neighbors = get_neighbors(x, y)
    count = neighbors.sum
    if @grid[x][y] == 1
      count > 1 ? 1 : 0
    else
      count == 3 ? 1 : 0
    end
  end

  def get_neighbors(x, y)
    directions = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]
    neighbors = []
    directions.each do |dx, dy|
      nx, ny = ((x + dx) % @size, (y + dy) % @size)
      neighbors << @grid[nx][ny]
    end
    neighbors
  end
end

class BoundaryConditionApplier
  def initialize(simulator)
    @simulator = simulator
  end

  def apply
    (0...@simulator.size).each do |i|
      @simulator.grid[i][0] = 1
      @simulator.grid[i][-1] = 1
      @simulator.grid[0][i] = 1
      @simulator.grid[-1][i] = 1
    end
  end
end

def main
  grid_size = 10
  simulator = FluidSimulator.new(grid_size)
  boundary_conditions = BoundaryConditionApplier.new(simulator)
  loop do
    boundary_conditions.apply
    simulator.update
  end
end

main