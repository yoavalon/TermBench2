class CellularAutomata
  def initialize(size, rule)
    @grid = Array.new(size) { Array.new(size, 0) }
    @rule = rule
    @size = size
  end

  def set_initial_state(x, y)
    @grid[x][y] = 1
  end

  def get_neighbors(x, y)
    count = 0
    (-1..1).each do |i|
      (-1..1).each do |j|
        next if i == 0 && j == 0
        nx, ny = ((x + i) % @size), ((y + j) % @size)
        count += @grid[nx][ny]
      end
    end
    count
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        n = get_neighbors(i, j)
        new_grid[i][j] = apply_rule(@grid[i][j], n)
      end
    end
    @grid = new_grid
  end

  def apply_rule(state, neighbors)
    if state == 0 && neighbors == @rule
      return 1
    end
    0
  end
end

def main
  ca = CellularAutomata.new(10, 3)
  ca.set_initial_state(5, 5)
  loop do
    ca.update
  end
end

main