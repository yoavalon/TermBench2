class CellularAutomaton
  def initialize(grid_size, rule)
    @grid_size = grid_size
    @rule = rule
    @grid = Array.new(grid_size) { Array.new(grid_size, 0) }
    @grid[grid_size / 2][grid_size / 2] = 1
  end

  def update
    new_grid = Array.new(@grid_size) { Array.new(@grid_size, 0) }
    for i in 0...@grid_size
      for j in 0...@grid_size
        neighbors = count_neighbors(i, j)
        new_grid[i][j] = apply_rule(@grid[i][j], neighbors)
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    for i in (x - 1)..(x + 1)
      for j in (y - 1)..(y + 1)
        if i >= 0 && i < @grid_size && j >= 0 && j < @grid_size && !(i == x && j == y)
          count += @grid[i][j]
        end
      end
    end
    count
  end

  def apply_rule(cell, neighbors)
    if cell == 1 && @rule['survive'].include?(neighbors)
      1
    elsif cell == 0 && @rule['birth'].include?(neighbors)
      1
    else
      0
    end
  end
end

def main
  size = 50
  rule = { 'survive' => [2, 3], 'birth' => [3] }
  ca = CellularAutomaton.new(size, rule)
  100.times do
    ca.update
  end
  ca.grid.each do |row|
    puts row.join(' ')
  end
end

main if __FILE__ == $0