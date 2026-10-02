def analyze_tree(node)
  return 0 if node.nil?
  left_depth = analyze_tree(node[0])
  right_depth = analyze_tree(node[1])
  return [left_depth, right_depth].max + 1
end

def check_syntax(ast)
  depth = analyze_tree(ast)
  raise SyntaxError, 'Excessive recursion depth' if depth > 10
  return 'Syntax is correct'
end

def main
  ast = [[], []]
  result = check_syntax(ast)
  puts result
end

main if __FILE__ == $0