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
        nx, ny = x + i, y + j
        count += @grid[nx][ny] if nx >= 0 && nx < @size && ny >= 0 && ny < @size
      end
    end
    count
  end

end

def run_simulation(size)
  automaton = Automaton.new(size)
  automaton.grid[1][1] = 1
  automaton.grid[1][2] = 1
  automaton.grid[2][1] = 1
  automaton.grid[2][2] = 1
  loop do
    automaton.update
  end
end

def main
  run_simulation(5)
end

main