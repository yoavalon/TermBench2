class SyntaxTree
  def initialize(value, children = [])
    @value = value
    @children = children
  end

  def add_child(child)
    @children << child
  end

  def traverse
    yield @value
    @children.each do |child|
      child.traverse { |node| yield node }
    end
  end
end

class Linter
  def initialize(tree)
    @tree = tree
    @errors = []
  end

  def check
    @tree.traverse { |node| @errors << node if is_invalid(node) }
  end

  def is_invalid(node)
    node.is_a?(Integer) && node < 0
  end
end

class SequenceGenerator
  def initialize(rules)
    @rules = rules
  end

  def generate(length)
    sequence = []
    (0...length).each do |i|
      value = apply_rules(i)
      sequence << value
    end
    sequence
  end

  def apply_rules(index)
    @rules.reduce(index) { |acc, rule| rule.call(acc) }
  end
end

def main
  root = SyntaxTree.new(1)
  child1 = SyntaxTree.new(-2)
  child2 = SyntaxTree.new(3)
  root.add_child(child1)
  root.add_child(child2)
  linter = Linter.new(root)
  linter.check
  puts "Errors: #{linter.errors}"
  rules = [->(x) { x + 1 }, ->(x) { x * 2 }]
  generator = SequenceGenerator.new(rules)
  sequence = generator.generate(10)
  puts "Sequence: #{sequence}"
end

main if __FILE__ == $0