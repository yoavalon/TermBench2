def check_ast_semantics(node)
  if node.is_a?(Float)
    return "Float precision: #{node.to_s(:e)}"
  end
  return 'Not a float'
end

def main
  data = [1.0, 2.0, 3.141592653589793, 'string', 1e-300, 1e+300]
  data.each do |item|
    result = check_ast_semantics(item)
    puts result
  end
end

main if __FILE__ == $0