require 'matrix'

class Automaton

  def initialize(size, rules)
    @grid = Array.new(size) { Array.new(size) { rand(2) } }
    @rules = rules
  end

  def apply_rules
    new_grid = @grid.map { |row| row.dup }
    (1...@grid.size - 1).each do |i|
      (1...@grid[i].size - 1).each do |j|
        neighbors = @grid[i-1..i+1].map { |row| row[j-1..j+1] }
        total = neighbors.flatten.sum
        if @rules.key?(total)
          new_grid[i][j] = @rules[total]
        end
      end
    end
    @grid = new_grid
  end

  def update
    apply_rules
  end
end

class Simulation

  def initialize(size, rules, steps)
    @automaton = Automaton.new(size, rules)
    @steps = steps
  end

  def run
    @steps.times do
      @automaton.update
    end
  end
end

def main
  size = 10
  rules = {3 => 1, 12 => 1}
  steps = 50
  simulation = Simulation.new(size, rules, steps)
  simulation.run
end

main