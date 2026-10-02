class Automaton
  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
  end

  def update
    new_grid = Array.new(@grid.size) { Array.new(@grid.size, 0) }
    (0...@grid.size).each do |i|
      (0...@grid[i].size).each do |j|
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
    (-1..1).each do |i|
      (-1..1).each do |j|
        next if i == 0 && j == 0
        ni, nj = x + i, y + j
        count += @grid[ni][nj] if ni >= 0 && ni < @grid.size && nj >= 0 && nj < @grid[ni].size
      end
    end
    count
  end
end

def main
  size = 50
  automaton = Automaton.new(size)
  automaton.grid[size / 2][size / 2] = 1
  automaton.update
  loop do
    automaton.update
  end
end

main