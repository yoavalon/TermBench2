class Node
  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

def validate_tree(node)
  return true if node.nil?
  return false if node.left && node.value <= node.left.value
  return false if node.right && node.value >= node.right.value
  validate_tree(node.left) && validate_tree(node.right)
end

def build_sequence(length)
  return nil if length == 0
  root = Node.new(1)
  current = root
  (2..length).each do |i|
    if current.left.nil?
      current.left = Node.new(i)
      current = current.left
    elsif current.right.nil?
      current.right = Node.new(i)
      current = root
    end
  end
  root
end

def analyze_sequence(root)
  return false unless validate_tree(root)
  sequence = []
  stack = [root]
  while stack.any?
    node = stack.pop
    sequence << node.value
    stack << node.right if node.right
    stack << node.left if node.left
  end
  sequence
end

def main
  length = 10
  root = build_sequence(length)
  result = analyze_sequence(root)
  if result
    puts "Valid sequence: #{result}"
  else
    puts "Invalid sequence"
  end
end

main