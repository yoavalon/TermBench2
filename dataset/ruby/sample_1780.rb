class CellularAutomata
  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
  end

  def update
    new_grid = Array.new(@grid.length) { Array.new(@grid.length, 0) }
    (0...@grid.length).each do |i|
      (0...@grid.length).each do |j|
        neighbors = count_neighbors(i, j)
        if @grid[i][j] == 0 && neighbors == 3
          new_grid[i][j] = 1
        elsif @grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)
          new_grid[i][j] = 0
        else
          new_grid[i][j] = @grid[i][j]
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (max(0, x - 1)..min(@grid.length, x + 2) - 1).each do |i|
      (max(0, y - 1)..min(@grid.length, y + 2) - 1).each do |j|
        count += 1 if [i, j] != [x, y] && @grid[i][j] == 1
      end
    end
    count
  end
end

def main
  size = 10
  ca = CellularAutomata.new(size)
  ca.grid[1][1] = 1
  ca.grid[2][2] = 1
  ca.grid[2][3] = 1
  ca.grid[3][1] = 1
  ca.grid[3][2] = 1
  loop do
    ca.update
    ca.grid.each do |row|
      puts row.join(' ')
    end
    puts
  end
end

main