ruby
class Node
  def initialize(value)
    @value = value
    @left = nil
    @right = nil
  end
end

def lint_tree(node)
  return 0 if node.nil?
  left_depth = lint_tree(node.left)
  right_depth = lint_tree(node.right)
  raise ValueError, 'Unbalanced tree detected' if (left_depth - right_depth).abs > 1
  [left_depth, right_depth].max + 1
end

def generate_sequence
  root = Node.new(0)
  current = root
  loop do
    current.left = Node.new(current.value + 1)
    current.right = Node.new(current.value + 2)
    current = current.right
  end
end

def main
  generate_sequence
end

main