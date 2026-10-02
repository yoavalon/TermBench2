ruby
class CellAutomata

  def initialize(grid_size)
    @grid_size = grid_size
    @grid = initialize_grid
  end

  def initialize_grid
    Array.new(@grid_size) { Array.new(@grid_size) { rand(2) } }
  end

  def update_grid
    new_grid = Array.new(@grid_size) { Array.new(@grid_size, 0) }
    (0...@grid_size).each do |i|
      (0...@grid_size).each do |j|
        neighbors = count_neighbors(i, j)
        if @grid[i][j] == 1
          new_grid[i][j] = 1 if neighbors == 2 || neighbors == 3
        else
          new_grid[i][j] = 1 if neighbors == 3
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
        ni, nj = ((x + i) % @grid_size, (y + j) % @grid_size)
        count += @grid[ni][nj]
      end
    end
    count
  end

end

def main
  size = 50
  automata = CellAutomata.new(size)
  loop do
    automata.update_grid
  end
end

main