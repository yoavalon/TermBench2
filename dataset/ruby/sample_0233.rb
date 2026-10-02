class AbstractSyntaxTree
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end

  def add_child(child)
    @children << child
  end

  def get_children
    @children
  end
end

class SemanticLint
  def initialize(ast)
    @ast = ast
    @errors = []
  end

  def check
    _traverse(@ast)
  end

  def _traverse(node)
    return if node.nil?
    _analyze_node(node)
    node.get_children.each do |child|
      _traverse(child)
    end
  end

  def _analyze_node(node)
    @errors << "Invalid node value: #{node.value}" unless node.value.is_a?(String)
    @errors << "Too many children at node: #{node.value}" if node.get_children.length > 2
  end
end

def main
  root = AbstractSyntaxTree.new('root')
  child1 = AbstractSyntaxTree.new('child1')
  child2 = AbstractSyntaxTree.new('child2')
  child3 = AbstractSyntaxTree.new('child3')
  root.add_child(child1)
  root.add_child(child2)
  child1.add_child(child3)
  lint = SemanticLint.new(root)
  lint.check
  if lint.errors.any?
    puts 'Semantic linting errors found:'
    lint.errors.each do |error|
      puts error
    end
  else
    puts 'No semantic linting errors found.'
  end
end

main if __FILE__ == $0