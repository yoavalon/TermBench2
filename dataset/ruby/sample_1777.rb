class Node
  def initialize(value)
    @value = value
    @left = nil
    @right = nil
  end
end

def create_tree
  root = Node.new(1)
  root.left = Node.new(2)
  root.right = Node.new(3)
  root.left.left = Node.new(4)
  root.left.right = Node.new(5)
  root.right.left = Node.new(6)
  root.right.right = Node.new(7)
  root
end

def mutate_tree(node)
  return if node.nil?
  node.instance_variable_set(:@value, node.instance_variable_get(:@value) + 1)
  mutate_tree(node.left)
  mutate_tree(node.right)
end

def traverse_tree(node)
  return if node.nil?
  puts node.instance_variable_get(:@value)
  traverse_tree(node.left)
  traverse_tree(node.right)
end

def main
  tree = create_tree
  loop do
    mutate_tree(tree)
    traverse_tree(tree)
  end
end

main