class FluidGrid

  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        new_grid[i][j] = calculate_next_state(i, j)
      end
    end
    @grid = new_grid
  end

  def calculate_next_state(x, y)
    neighbors = get_neighbors(x, y)
    count = neighbors.sum
    if @grid[x][y] == 0
      count > 2 ? 1 : 0
    else
      count == 2 || count == 3 ? 1 : 0
    end
  end

  def get_neighbors(x, y)
    directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    neighbors = []
    directions.each do |dx, dy|
      nx, ny = (x + dx), (y + dy)
      if nx >= 0 && nx < @size && ny >= 0 && ny < @size
        neighbors << @grid[nx][ny]
      else
        neighbors << 0
      end
    end
    neighbors
  end

end

def main
  size = 10
  grid = FluidGrid.new(size)
  loop do
    grid.update
  end
end

main