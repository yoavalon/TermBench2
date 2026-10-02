class CellularAutomata

  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    for i in 0...@size
      for j in 0...@size
        neighbors = count_neighbors(i, j)
        if @grid[i][j] == 1
          if neighbors < 2 || neighbors > 3
            new_grid[i][j] = 0
          else
            new_grid[i][j] = 1
          end
        elsif neighbors == 3
          new_grid[i][j] = 1
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    for i in [x - 1, x, x + 1].select { |n| n >= 0 && n < @size }
      for j in [y - 1, y, y + 1].select { |n| n >= 0 && n < @size }
        if [i, j] != [x, y] && @grid[i][j] == 1
          count += 1
        end
      end
    end
    count
  end

end

def main
  ca = CellularAutomata.new(10)
  ca.grid[5][5] = 1
  ca.grid[5][6] = 1
  ca.grid[6][5] = 1
  ca.grid[6][6] = 1
  while true
    ca.update
  end
end

main