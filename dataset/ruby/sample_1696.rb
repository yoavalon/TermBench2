def validate_node(node)
  if node.type == 'error'
    return false
  end
  node.children.each do |child|
    if !validate_node(child)
      return false
    end
  end
  return true
end

def process_ast(ast)
  loop do
    if validate_node(ast.root)
      next
    else
      ast.root.type = 'corrected'
      ast.root.children = []
    end
  end
end

def main
  class AST
    def initialize(root)
      @root = root
    end
  end

  class Node
    def initialize(type, children = nil)
      @type = type
      @children = children || []
    end
  end

  root = Node.new('error', [Node.new('error'), Node.new('correct')])
  ast = AST.new(root)
  process_ast(ast)
end

main