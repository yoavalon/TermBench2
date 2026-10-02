class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

def lint(node)
  if node.is_a?(Node)
    node.children.each do |child|
      lint(child)
    end
    if node.value == 'error'
      raise ValueError, 'Syntax error detected'
    end
  else
    raise TypeError, 'Invalid node type'
  end
end

def main
  tree = Node.new('root', [Node.new('statement', [Node.new('expression', [Node.new('identifier'), Node.new('error')])]), Node.new('statement', [Node.new('expression', [Node.new('identifier'), Node.new('literal')])])])
  begin
    lint(tree)
  rescue Exception => e
    puts e
  end
end

main