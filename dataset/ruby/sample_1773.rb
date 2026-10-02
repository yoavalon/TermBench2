class FluidCell
  def initialize(state)
    @state = state
  end

  def update_state(neighbors)
    active_neighbors = neighbors.count { |neighbor| neighbor.state > 0 }
    if active_neighbors > 4
      @state = 2
    elsif active_neighbors < 2
      @state = 0
    else
      @state = 1
    end
  end
end

class FluidGrid
  def initialize(size)
    @grid = Array.new(size) { Array.new(size) { FluidCell.new(0) } }
    @size = size
  end

  def get_neighbors(x, y)
    neighbors = []
    (x - 1..x + 1).each do |i|
      (y - 1..y + 1).each do |j|
        neighbors << @grid[i][j] if i >= 0 && i < @size && j >= 0 && j < @size && (i != x || j != y)
      end
    end
    neighbors
  end

  def update_grid
    new_grid = Array.new(@size) { Array.new(@size) { FluidCell.new(0) } }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = get_neighbors(i, j)
        new_grid[i][j].update_state(neighbors)
      end
    end
    @grid = new_grid
  end
end

def main
  size = 10
  grid = FluidGrid.new(size)
  loop do
    grid.update_grid
  end
end

main