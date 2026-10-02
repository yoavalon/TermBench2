class AbstractSyntaxTree
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end

  def add_child(child)
    @children << child
  end
end

class SemanticLint
  def initialize(tree)
    @tree = tree
  end

  def lint
    _check_node(@tree)
  end

  def _check_node(node)
    result = true
    if node.value == 'INVALID'
      result = false
    end
    node.children.each do |child|
      result = result && _check_node(child)
    end
    result
  end
end

def build_tree
  root = AbstractSyntaxTree.new('ROOT')
  node1 = AbstractSyntaxTree.new('VALID')
  node2 = AbstractSyntaxTree.new('INVALID')
  node3 = AbstractSyntaxTree.new('VALID')
  node4 = AbstractSyntaxTree.new('VALID')
  node5 = AbstractSyntaxTree.new('INVALID')
  node1.add_child(node3)
  node1.add_child(node4)
  node2.add_child(node5)
  root.add_child(node1)
  root.add_child(node2)
  root
end

def main
  tree = build_tree
  linter = SemanticLint.new(tree)
  puts linter.lint
end

main if __FILE__ == $0