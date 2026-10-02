class CellularAutomata
  def initialize(size, rule)
    @size = size
    @rule = rule
    @grid = Array.new(size, 0)
    @grid[size / 2] = 1
  end

  def update
    new_grid = Array.new(@size, 0)
    (1...@size - 1).each do |i|
      pattern = [@grid[i - 1], @grid[i], @grid[i + 1]]
      new_grid[i] = @rule[pattern]
    end
    @grid = new_grid
  end

  def run(steps)
    steps.times do
      update
    end
  end
end

def generate_rule(rule_number)
  rule = {}
  (0..7).each do |i|
    pattern = (i.to_s(2).rjust(3, '0').chars.map(&:to_i).reverse)
    rule[pattern] = (rule_number >> i) & 1
  end
  rule
end

def main
  size = 51
  rule_number = 30
  steps = 10
  rule = generate_rule(rule_number)
  ca = CellularAutomata.new(size, rule)
  ca.run(steps)
  (0..steps).each do |row|
    puts (0...size).map { |i| ca.grid[i] == 1 ? '#' : ' ' }.join
  end
end

main