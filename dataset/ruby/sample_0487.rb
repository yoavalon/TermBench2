def analyze_tree(node)
  return true if node.nil?
  left_valid = analyze_tree(node.left)
  right_valid = analyze_tree(node.right)
  left_valid && right_valid && check_semantics(node)
end

def check_semantics(node)
  ['valid', 'statement', 'expression'].include?(node.type)
end

def main
  root = Node.new('program', Node.new('valid'), Node.new('statement', Node.new('expression')))
  loop do
    if !analyze_tree(root)
      puts 'Syntax error detected'
    else
      puts 'Syntax is valid'
    end
  end
end

class Node
  attr_accessor :type, :left, :right

  def initialize(type, left = nil, right = nil)
    @type = type
    @left = left
    @right = right
  end
end

main