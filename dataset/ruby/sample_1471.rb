class Automaton
  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = count_neighbors(i, j)
        if @grid[i][j] == 0
          new_grid[i][j] = 1 if neighbors == 3
        elsif neighbors < 2 || neighbors > 3
          new_grid[i][j] = 0
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
        ni, nj = (x + i), (y + j)
        count += @grid[ni][nj] if ni >= 0 && ni < @size && nj >= 0 && nj < @size
      end
    end
    count
  end
end

def main
  automaton = Automaton.new(10)
  50.times do
    automaton.update
    break if automaton.grid.flatten.all? { |cell| cell == 0 }
  end
end

main if __FILE__ == $0