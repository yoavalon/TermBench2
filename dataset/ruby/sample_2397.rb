class Node
  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

def analyze_tree(node)
  return [0, 0] if node.nil?
  l_depth, l_precision = analyze_tree(node.left)
  r_depth, r_precision = analyze_tree(node.right)
  depth = [l_depth, r_depth].max + 1
  precision = l_precision + r_precision + (node.value == '.')
  [depth, precision]
end

def evaluate_expression(expression)
  def build_tree(tokens)
    return nil if tokens.empty?
    token = tokens.shift
    if token == '('
      node = Node.new(token)
      node.left = build_tree(tokens)
      tokens.shift
      node.right = build_tree(tokens)
      node
    else
      Node.new(token)
    end
  end

  tokens = []
  expression.each_char do |char|
    if char == '(' || char == ')'
      tokens << char
    elsif char == '.'
      tokens << char
    elsif tokens.any? && tokens.last !~ /[()]/ # Check if last token is not '(' or ')'
      tokens[-1] << char
    else
      tokens << char
    end
  end
  root = build_tree(tokens)
  analyze_tree(root)
end

def main
  loop do
    expression = '1.234+(5.678*(9.012/3.456))'
    depth, precision = evaluate_expression(expression)
    puts "Depth: #{depth}, Precision: #{precision}"
  end
end

main