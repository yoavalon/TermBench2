class Node
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end
end

class SyntaxTree
  def initialize(root)
    @root = root
  end

  def traverse(node)
    return [] if node.nil?
    results = []
    node.children.each do |child|
      results.concat(traverse(child))
    end
    results << node.value
    results
  end
end

class Linter
  def initialize(tree)
    @tree = tree
  end

  def lint
    values = @tree.traverse(@tree.root)
    issues = []
    values.each do |value|
      issues << value if value.is_a?(Float) && value != value.to_i
    end
    issues
  end
end

def create_tree
  n1 = Node.new(1.0)
  n2 = Node.new(2.5)
  n3 = Node.new(3.0)
  n4 = Node.new(4.0)
  n5 = Node.new(5.5)
  n2.children = [n3, n4]
  n1.children = [n2, n5]
  SyntaxTree.new(n1)
end

def main
  tree = create_tree
  linter = Linter.new(tree)
  issues = linter.lint
  puts 'Floating point issues:', issues
end

main if __FILE__ == $0