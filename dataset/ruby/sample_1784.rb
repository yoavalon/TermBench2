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
        if @grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)
          new_grid[i][j] = 0
        elsif @grid[i][j] == 0 && neighbors == 3
          new_grid[i][j] = 1
        else
          new_grid[i][j] = @grid[i][j]
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (max(0, x - 1)...min(@size, x + 2)).each do |i|
      (max(0, y - 1)...min(@size, y + 2)).each do |j|
        count += 1 if [i, j] != [x, y] && @grid[i][j] == 1
      end
    end
    count
  end
end

def run_simulation(size, steps)
  automaton = Automaton.new(size)
  steps.times do
    automaton.update
  end
  automaton.grid
end

def main
  size = 50
  steps = 1000
  result = run_simulation(size, steps)
  result.each do |row|
    puts row.map { |cell| cell == 1 ? '#' : '.' }.join
  end
end

main