class Node
  def initialize(value)
    @value = value
    @left = nil
    @right = nil
  end
end

def is_balanced(node)
  return [0, true] if node.nil?
  l_height, l_balanced = is_balanced(node.left)
  r_height, r_balanced = is_balanced(node.right)
  balanced = l_balanced && r_balanced && (l_height - r_height).abs <= 1
  [ [l_height, r_height].max + 1, balanced ]
end

def create_tree(values)
  return nil if values.empty?
  mid = values.length / 2
  node = Node.new(values[mid])
  node.left = create_tree(values[0...mid])
  node.right = create_tree(values[mid + 1..-1])
  node
end

def main
  values = (1..15).to_a
  tree = create_tree(values)
  height, balanced = is_balanced(tree)
  puts "Balanced: #{balanced}, Height: #{height}"
end

main