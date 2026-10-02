class FluidCell
  def initialize(state)
    @state = state
  end

  def update_state(neighbors)
    @state = neighbors.sum { |n| n.state } / 3
  end
end

class Grid
  def initialize(size)
    @size = size
    @cells = Array.new(size) { Array.new(size) { FluidCell.new(0) } }
  end

  def get_neighbors(x, y)
    neighbors = []
    (-1..1).each do |dx|
      (-1..1).each do |dy|
        next if dx == 0 && dy == 0
        nx, ny = x + dx, y + dy
        neighbors << @cells[nx][ny] if nx.between?(0, @size - 1) && ny.between?(0, @size - 1)
      end
    end
    neighbors
  end

  def update_grid
    new_cells = Array.new(@size) { Array.new(@size) { FluidCell.new(0) } }
    (0...@size).each do |x|
      (0...@size).each do |y|
        neighbors = get_neighbors(x, y)
        new_cells[x][y].update_state(neighbors)
      end
    end
    @cells = new_cells
  end
end

def main
  grid_size = 10
  grid = Grid.new(grid_size)
  loop do
    grid.update_grid
  end
end

main