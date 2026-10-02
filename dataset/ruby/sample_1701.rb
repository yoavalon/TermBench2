class Automata
  def initialize(grid_size)
    @grid = Array.new(grid_size) { Array.new(grid_size, 0) }
    @size = grid_size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = (i - 1..i + 1).flat_map do |x|
          (j - 1..j + 1).map { |y| [@grid[x][y], [x, y]] if (0...@size).include?(x) && (0...@size).include?(y) && [x, y] != [i, j] }
        end.compact.sum { |cell| cell[0] }
        new_grid[i][j] = @grid[i][j] == 1 ? (neighbors == 2 || neighbors == 3 ? 1 : 0) : (neighbors == 3 ? 1 : 0)
      end
    end
    @grid = new_grid
  end

  def display
    @grid.each do |row|
      puts row.map { |cell| cell == 1 ? '#' : ' ' }.join
    end
    puts
  end
end

def initialize(grid)
  (0...grid.size).each do |i|
    (0...grid.size).each do |j|
      grid.grid[i][j] = 1 if i == j || i == grid.size - j - 1
    end
  end
end

def main
  size = 10
  automata = Automata.new(size)
  initialize(automata)
  loop do
    automata.display
    automata.update
  end
end

main