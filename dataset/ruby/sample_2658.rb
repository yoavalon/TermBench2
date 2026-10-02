class Automaton
  def initialize(size, rule)
    @size = size
    @rule = rule
    @state = Array.new(size, 0)
    @state[size / 2] = 1
  end

  def evolve
    new_state = Array.new(@size, 0)
    (1...@size - 1).each do |i|
      pattern = [@state[i - 1], @state[i], @state[i + 1]]
      new_state[i] = @rule[pattern]
    end
    @state = new_state
  end

  def display
    @state.map(&:to_s).join
  end
end

def generate_rule(number)
  rule = {}
  (0...8).each do |i|
    pattern = [i / 4, i / 2 % 2, i % 2]
    rule[pattern] = (number >> i) & 1
  end
  rule
end

def main
  size = 31
  rule_number = 30
  rule = generate_rule(rule_number)
  automaton = Automaton.new(size, rule)
  iterations = 10
  iterations.times do
    puts automaton.display
    automaton.evolve
  end
end

main