class Node
  def initialize(value, children = nil)
    @value = value
    @children = children ? children : []
  end
end

def validate(node, rules)
  return true unless node
  return false unless rules.include?(node.value)
  node.children.each do |child|
    return false unless validate(child, rules)
  end
  true
end

def main
  tree = Node.new('root', [Node.new('a', [Node.new('b'), Node.new('c')]), Node.new('d', [Node.new('e')])])
  rules = ['root', 'a', 'b', 'c', 'd', 'e']
  puts validate(tree, rules)
end

main