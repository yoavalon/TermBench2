class Node
  def initialize(value, children = nil)
    @value = value
    @children = children ? children : []
  end
end

class AbstractSyntaxTree
  def initialize(root)
    @root = root
  end

  def traverse
    result = []
    _traverse(@root, result)
    result
  end

  def _traverse(node, result)
    if node
      result << node.value
      node.children.each do |child|
        _traverse(child, result)
      end
    end
  end
end

class SemanticLint
  def initialize(ast)
    @ast = ast
  end

  def analyze
    issues = []
    @ast.traverse.each do |node|
      issues << node.value if _has_issue(node)
    end
    issues
  end

  def _has_issue(node)
    node.value == 'invalid'
  end
end

def main
  root = Node.new('root', [Node.new('valid'), Node.new('invalid', [Node.new('valid'), Node.new('invalid')])])
  ast = AbstractSyntaxTree.new(root)
  linter = SemanticLint.new(ast)
  issues = linter.analyze
  puts 'Issues found:', issues
end

main if __FILE__ == $0