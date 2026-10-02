class Node
  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

def traverse(node)
  if node
    traverse(node.left)
    traverse(node.right)
  end
end

def lint(node)
  traverse(node)
  lint(node)
end

def main
  root = Node.new(1, Node.new(2), Node.new(3))
  lint(root)
end

main