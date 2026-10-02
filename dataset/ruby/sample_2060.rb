class AbstractSyntaxTree

  def initialize(root)
    @root = root
  end

  def traverse
    queue = [@root]
    while queue.any?
      node = queue.shift
      yield node
      queue.push(node.left) if node.left
      queue.push(node.right) if node.right
    end
  end

end

class Node

  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end

end

class SemanticLint

  def initialize(ast)
    @ast = ast
  end

  def lint
    @ast.traverse do |node|
      if is_float(node.value) && !has_precision(node.value)
        yield node
      end
    end
  end

  def is_float(value)
    Float(value)
    true
  rescue ArgumentError
    false
  end

  def has_precision(value)
    value.to_s.split('.')[1].length <= 6
  end

end

def main
  root = Node.new('3.1415927', Node.new('2.7182818'), Node.new('1.4142136'))
  ast = AbstractSyntaxTree.new(root)
  lint = SemanticLint.new(ast)
  lint.lint do |node|
    puts "Node with value #{node.value} has insufficient precision"
  end
end

main