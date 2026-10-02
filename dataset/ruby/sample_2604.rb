class CellularAutomaton
  def initialize(size, rules)
    @size = size
    @rules = rules
    @state = Array.new(size, 0)
  end

  def update
    new_state = Array.new(@size, 0)
    @size.times do |i|
      left = i > 0 ? @state[i - 1] : @state[-1]
      right = @state[(i + 1) % @size]
      neighborhood = [left, @state[i], right]
      new_state[i] = @rules[neighborhood]
    end
    @state = new_state
  end

  def display
    @state.map(&:to_s).join
  end
end

def generate_rules(rule_number)
  rules = {}
  8.times do |i|
    neighborhood = [i / 4, i / 2 % 2, i % 2]
    rules[neighborhood] = (rule_number >> i) & 1
  end
  rules
end

def simulate_automaton(size, rule_number, steps)
  automaton = CellularAutomaton.new(size, generate_rules(rule_number))
  automaton.state[size / 2] = 1
  steps.times do
    yield automaton.display
    automaton.update
  end
end

def main
  size = 31
  rule_number = 30
  steps = 10
  simulate_automaton(size, rule_number, steps) do |state|
    puts state
  end
end

main