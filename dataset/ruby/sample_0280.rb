class Grid

  def initialize(size)
    @size = size
    @data = Array.new(size) { Array.new(size, 0) }
  end

  def update
    new_data = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        new_data[i][j] = _calculate_next_state(i, j)
      end
    end
    @data = new_data
  end

  def _calculate_next_state(i, j)
    neighbors = _get_neighbors(i, j)
    alive_count = neighbors.sum
    if @data[i][j] == 1
      alive_count == 2 || alive_count == 3 ? 1 : 0
    else
      alive_count == 3 ? 1 : 0
    end
  end

  def _get_neighbors(i, j)
    neighbors = []
    (max(0, i - 1)...min(@size, i + 2)).each do |x|
      (max(0, j - 1)...min(@size, j + 2)).each do |y|
        unless (x, y) == [i, j]
          neighbors << @data[x][y]
        end
      end
    end
    neighbors
  end

end

def main
  grid_size = 10
  grid = Grid.new(grid_size)
  steps = 50
  steps.times do
    grid.update
  end
end

main if __FILE__ == $0