class Automaton
  def initialize(grid_size, rule)
    @grid = Array.new(grid_size) { Array.new(grid_size, 0) }
    @rule = rule
    @grid_size = grid_size
  end

  def set_initial_state(state)
    (0...@grid_size).each do |i|
      (0...@grid_size).each do |j|
        @grid[i][j] = state[i][j]
      end
    end
  end

  def update
    new_grid = Array.new(@grid_size) { Array.new(@grid_size, 0) }
    (0...@grid_size).each do |i|
      (0...@grid_size).each do |j|
        neighbors = [
          @grid[(i - 1) % @grid_size][(j - 1) % @grid_size],
          @grid[(i - 1) % @grid_size][j],
          @grid[(i - 1) % @grid_size][(j + 1) % @grid_size],
          @grid[i][(j - 1) % @grid_size],
          @grid[i][(j + 1) % @grid_size],
          @grid[(i + 1) % @grid_size][(j - 1) % @grid_size],
          @grid[(i + 1) % @grid_size][j],
          @grid[(i + 1) % @grid_size][(j + 1) % @grid_size]
        ]
        new_grid[i][j] = apply_rule(neighbors)
      end
    end
    @grid = new_grid
  end

  def apply_rule(neighbors)
    @rule.call(neighbors.sum)
  end
end

class Rule
  def initialize(threshold)
    @threshold = threshold
  end

  def call(count)
    count > @threshold ? 1 : 0
  end
end

def main
  grid_size = 10
  initial_state = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 1, 1, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
  ]
  rule = Rule.new(3)
  automaton = Automaton.new(grid_size, rule)
  automaton.set_initial_state(initial_state)
  loop do
    automaton.update
  end
end

main