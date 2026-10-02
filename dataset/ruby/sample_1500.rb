class AutomataSimulator
  def initialize(size, rule)
    @grid = Array.new(size) { Array.new(size, 0) }
    @rule = rule
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        state = @grid[i][j]
        neighbors = count_neighbors(i, j)
        new_state = apply_rule(state, neighbors)
        new_grid[i][j] = new_state
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (x - 1..x + 1).each do |i|
      (y - 1..y + 1).each do |j|
        count += @grid[i][j] if i.between?(0, @size - 1) && j.between?(0, @size - 1) && !(i == x && j == y)
      end
    end
    count
  end

  def apply_rule(state, neighbors)
    @rule[state][neighbors]
  end
end

def main
  size = 10
  rule = {0 => {0 => 0, 1 => 1, 2 => 1, 3 => 1, 4 => 0, 5 => 0, 6 => 0, 7 => 0, 8 => 0}, 1 => {0 => 0, 1 => 0, 2 => 0, 3 => 1, 4 => 0, 5 => 0, 6 => 0, 7 => 0, 8 => 0}}
  automata = AutomataSimulator.new(size, rule)
  100.times { automata.update }
  puts automata.instance_variable_get(:@grid).inspect
end

main if $0 == __FILE__