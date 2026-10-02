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
        else
          new_grid[i][j] = 1
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

def display(grid)
  grid.each do |row|
    puts row.map { |cell| cell == 1 ? '#' : ' ' }.join
  end
end

def main
  size = 10
  automaton = Automaton.new(size)
  automaton.grid[5][5] = 1
  automaton.grid[5][6] = 1
  automaton.grid[6][5] = 1
  automaton.grid[6][6] = 1
  loop do
    display(automaton.grid)
    automaton.update
  end
end

main