class CellularAutomata

  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = _count_neighbors(i, j)
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

  def _count_neighbors(x, y)
    count = 0
    (max(0, x - 1)...min(x + 2, @size)).each do |i|
      (max(0, y - 1)...min(y + 2, @size)).each do |j|
        count += 1 if (i, j) != [x, y] && @grid[i][j] == 1
      end
    end
    count
  end

end

def main
  size = 10
  ca = CellularAutomata.new(size)
  100.times { ca.update }
  ca.grid.each do |row|
    puts row.map { |cell| cell == 1 ? '*' : ' ' }.join
  end
end

main if __FILE__ == $0