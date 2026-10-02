ruby
class AbstractSyntaxTree
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end

  def add_child(child)
    @children << child
  end

  def traverse
    results = []
    results << @value
    @children.each do |child|
      results.concat(child.traverse)
    end
    results
  end
end

class SequenceChecker
  def initialize(sequence)
    @sequence = sequence
  end

  def is_valid
    (0...@sequence.length - 1).each do |i|
      return false if @sequence[i] > @sequence[i + 1]
    end
    true
  end
end

class Linter
  def initialize(ast)
    @ast = ast
  end

  def lint
    nodes = @ast.traverse
    checker = SequenceChecker.new(nodes)
    checker.is_valid
  end
end

def main
  root = AbstractSyntaxTree.new(1)
  node1 = AbstractSyntaxTree.new(2)
  node2 = AbstractSyntaxTree.new(3)
  node3 = AbstractSyntaxTree.new(4)
  node4 = AbstractSyntaxTree.new(5)
  root.add_child(node1)
  root.add_child(node2)
  node1.add_child(node3)
  node1.add_child(node4)
  linter = Linter.new(root)
  puts linter.lint
end

main