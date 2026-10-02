class CellularAutomata
  def initialize(size, rule)
    @size = size
    @rule = rule
    @state = Array.new(size, 0)
    @state[size / 2] = 1
  end

  def apply_rule(left, center, right)
    index = 4 * left + 2 * center + right
    (@rule >> index) & 1
  end

  def next_generation
    new_state = Array.new(@size, 0)
    (0...@size).each do |i|
      left = @state[(i - 1) % @size]
      center = @state[i]
      right = @state[(i + 1) % @size]
      new_state[i] = apply_rule(left, center, right)
    end
    @state = new_state
  end

  def run(steps)
    results = []
    steps.times do
      results << @state.dup
      next_generation
    end
    results
  end
end

def generate_sequence(size, rule, steps)
  ca = CellularAutomata.new(size, rule)
  ca.run(steps)
end

def display_sequence(sequence)
  sequence.each do |row|
    puts row.map { |cell| cell == 1 ? '1' : '0' }.join
  end
end

def main
  size = 31
  rule = 30
  steps = 10
  sequence = generate_sequence(size, rule, steps)
  display_sequence(sequence)
end

main