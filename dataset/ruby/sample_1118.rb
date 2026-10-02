class Grid
  def initialize(size)
    @size = size
    @grid = Array.new(size) { Array.new(size, 0) }
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = count_neighbors(i, j)
        if @grid[i][j] == 0
          new_grid[i][j] = neighbors == 3 ? 1 : 0
        else
          new_grid[i][j] = neighbors == 2 || neighbors == 3 ? 1 : 0
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (-1..1).each do |i|
      (-1..1).each do |j|
        next if i == 0 && j == 0
        ni, nj = x + i, y + j
        count += @grid[ni][nj] if ni >= 0 && ni < @size && nj >= 0 && nj < @size
      end
    end
    count
  end
end

def display(grid)
  grid.grid.each do |row|
    puts row.join(' ')
  end
  puts
end

def main
  size = 10
  grid = Grid.new(size)
  loop do
    display(grid)
    grid.update
  end
end

main