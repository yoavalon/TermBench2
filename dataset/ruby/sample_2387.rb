class FluidCell
  def initialize(state)
    @state = state
  end

  def update_state(neighbors)
    @state = neighbors.map(&:state).sum / neighbors.size
  end
end

class FluidGrid
  def initialize(size, initial_state)
    @size = size
    @grid = Array.new(size) { Array.new(size) { FluidCell.new(initial_state) } }
  end

  def get_neighbors(x, y)
    neighbors = []
    (-1..1).each do |dx|
      (-1..1).each do |dy|
        nx, ny = x + dx, y + dy
        if nx >= 0 && nx < @size && ny >= 0 && ny < @size && (dx != 0 || dy != 0)
          neighbors << @grid[nx][ny]
        end
      end
    end
    neighbors
  end

  def update_grid
    new_grid = Array.new(@size) { Array.new(@size) { FluidCell.new(0) } }
    (0...@size).each do |x|
      (0...@size).each do |y|
        neighbors = get_neighbors(x, y)
        new_grid[x][y].update_state(neighbors)
      end
    end
    @grid = new_grid
  end
end

def main
  size = 10
  initial_state = 1.0
  grid = FluidGrid.new(size, initial_state)
  loop do
    grid.update_grid
  end
end

main