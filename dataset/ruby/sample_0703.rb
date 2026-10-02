class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

def traverse(node)
  return if node.nil?
  lint(node)
  node.children.each do |child|
    traverse(child)
  end
end

def lint(node)
  raise ArgumentError, 'Syntax error detected' if node.value == 'error'
end

def main
  tree = Node.new('root', [Node.new('child1', [Node.new('error'), Node.new('child1.1')]), Node.new('child2')])
  begin
    traverse(tree)
  rescue ArgumentError => e
    puts e.message
  end
end

main if __FILE__ == $0