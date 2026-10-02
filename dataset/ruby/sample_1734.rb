class CellularAutomaton
  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = _count_neighbors(i, j)
        if @grid[i][j] == 0
          if neighbors == 3
            new_grid[i][j] = 1
          end
        elsif neighbors < 2 || neighbors > 3
          new_grid[i][j] = 0
        else
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
        unless [i, j] == [x, y]
          count += @grid[i][j]
        end
      end
    end
    count
  end
end

def display(grid)
  grid.each do |row|
    puts row.map { |cell| cell == 1 ? '█' : ' ' }.join
  end
end

def main
  size = 10
  automaton = CellularAutomaton.new(size)
  loop do
    display(automaton.grid)
    automaton.update
  end
end

main