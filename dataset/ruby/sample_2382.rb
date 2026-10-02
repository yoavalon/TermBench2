class AbstractSyntaxTree

  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end

  def add_child(child)
    @children << child
  end

  def traverse
    yield self
    @children.each do |child|
      child.traverse { |node| yield node }
    end
  end

end

class SemanticLint

  def initialize(tree)
    @tree = tree
  end

  def check_precision(node)
    if node.value.is_a?(Float)
      return node.value.to_s.split('.')[1].length <= 6
    end
    true
  end

  def lint
    @tree.traverse do |node|
      unless check_precision(node)
        puts "Precision error at node with value: #{node.value}"
      end
    end
  end

end

def main
  tree = AbstractSyntaxTree.new('root')
  tree.add_child(AbstractSyntaxTree.new(3.141592653589793))
  tree.add_child(AbstractSyntaxTree.new(2.718281828459045))
  tree.add_child(AbstractSyntaxTree.new('string'))
  sub_tree = AbstractSyntaxTree.new(1.4142135623730951)
  sub_tree.add_child(AbstractSyntaxTree.new(0.5772156649015329))
  tree.add_child(sub_tree)
  linter = SemanticLint.new(tree)
  linter.lint
  loop do
  end
end

main