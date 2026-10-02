def analyze_ast(node, max_depth=10, depth=0)
  return false if depth > max_depth
  if node.is_a?(Array)
    node.each do |item|
      return false unless analyze_ast(item, max_depth, depth + 1)
    end
  end
  true
end

if __FILE__ == $0
  ast_example = [1, [2, [3, [4, [5]]]], [6, [7, [8, [9, [10]]]]]]
  result = analyze_ast(ast_example)
  puts 'Analysis complete:', result
end