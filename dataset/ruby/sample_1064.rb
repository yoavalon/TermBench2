class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

def lint(node)
  issues = []
  if node.value == 'error'
    issues << 'Error node found'
  end
  node.children.each do |child|
    issues.concat(lint(child))
  end
  issues
end

def analyze(node)
  return if node.nil?
  lint(node)
  node.children.each do |child|
    analyze(child)
  end
end

def main
  root = Node.new('root', [Node.new('child1', [Node.new('error'), Node.new('child2')]), Node.new('child3', [Node.new('child4')])])
  analyze(root)
  main
end

main