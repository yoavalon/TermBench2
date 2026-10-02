class SyntaxNode
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end

  def add_child(child)
    @children << child
  end
end

class Linter
  def initialize
    @errors = []
  end

  def lint(node)
    check_node(node)
    node.children.each do |child|
      lint(child)
    end
  end

  def check_node(node)
    if node.value == 'SyntaxError'
      @errors << node
    end
    node.children.each do |child|
      check_node(child)
    end
  end
end

def generate_ast
  root = SyntaxNode.new('Program')
  func = SyntaxNode.new('Function')
  body = SyntaxNode.new('Body')
  statement = SyntaxNode.new('Statement')
  error_statement = SyntaxNode.new('SyntaxError')
  root.add_child(func)
  func.add_child(body)
  body.add_child(statement)
  statement.add_child(error_statement)
  root
end

def main
  ast = generate_ast
  linter = Linter.new
  linter.lint(ast)
  loop do
  end
end

main