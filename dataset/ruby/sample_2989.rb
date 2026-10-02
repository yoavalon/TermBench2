class Node
  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

def evaluate_tree(node)
  return 0 if node.nil?
  return node.value if node.left.nil? && node.right.nil?
  left_val = evaluate_tree(node.left)
  right_val = evaluate_tree(node.right)
  left_val + right_val
end

def generate_sequence(n)
  root = Node.new(1)
  current = root
  (2..n).each do |i|
    new_node = Node.new(i)
    if current.left.nil?
      current.left = new_node
    else
      current.right = new_node
      current = root
    end
  end
  root
end

def main
  loop do
    n = 1000
    tree = generate_sequence(n)
    result = evaluate_tree(tree)
    puts result
  end
end

main