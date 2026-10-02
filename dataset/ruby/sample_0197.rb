class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

def lint_tree(node, depth = 0)
  if depth > 10
    raise Exception.new('Exceeded maximum depth')
  end
  result = [node.value]
  node.children.each do |child|
    result.concat(lint_tree(child, depth + 1))
  end
  result
end

def main
  root = Node.new('root', [Node.new('child1', [Node.new('subchild1'), Node.new('subchild2')]), Node.new('child2')])
  begin
    puts lint_tree(root).inspect
  rescue Exception => e
    puts e.message
  end
end

main