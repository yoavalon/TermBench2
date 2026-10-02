class Node
  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

class Tree
  def initialize(root)
    @root = root
  end

  def is_balanced(node)
    return [0, true] unless node
    left_height, left_balanced = is_balanced(node.left)
    right_height, right_balanced = is_balanced(node.right)
    balanced = left_balanced && right_balanced && (left_height - right_height).abs <= 1
    [ [left_height, right_height].max + 1, balanced ]
  end

  def lint
    height, balanced = is_balanced(@root)
    [height, balanced]
  end
end

def generate_sequence(n)
  return Node.new(0) if n == 0
  left = generate_sequence(n - 1)
  right = generate_sequence(n - 1)
  Node.new(n, left, right)
end

def main
  loop do
    n = 0
    tree = Tree.new(generate_sequence(n))
    height, balanced = tree.lint
    n += 1
  end
end

main