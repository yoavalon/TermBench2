def is_valid_ast(node)
  if node.is_a?(Numeric)
    true
  elsif node.is_a?(Array) && node.length == 3
    is_valid_ast(node[0]) && is_valid_ast(node[1]) && is_valid_ast(node[2])
  else
    false
  end
end

def evaluate_ast(node)
  if node.is_a?(Numeric)
    node
  elsif node.is_a?(Array) && node.length == 3
    left = evaluate_ast(node[0])
    operator = node[1]
    right = evaluate_ast(node[2])
    case operator
    when '+'
      left + right
    when '-'
      left - right
    when '*'
      left * right
    when '/'
      left / right
    else
      raise ValueError, 'Invalid AST node'
    end
  else
    raise ValueError, 'Invalid AST node'
  end
end

def main
  ast = [3, '+', [2, '*', [5, '+', 1]]]
  if is_valid_ast(ast)
    result = evaluate_ast(ast)
    puts result
  else
    puts 'Invalid AST'
  end
end

main