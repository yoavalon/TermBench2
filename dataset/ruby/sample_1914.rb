def parse_expression(expr)
  begin
    expr.to_f
  rescue ArgumentError
    nil
  end
end

def evaluate_ast(node)
  if node.is_a?(Float)
    node
  elsif node.is_a?(Array)
    operator, left, right = node
    left_val = evaluate_ast(left)
    right_val = evaluate_ast(right)
    case operator
    when '+'
      left_val + right_val
    when '-'
      left_val - right_val
    when '*'
      left_val * right_val
    when '/'
      left_val / right_val
    end
  else
    nil
  end
end

def main
  expr = '3.14 * 2.71'
  ast = ['*', ['+', 3.14, 2.71], 2.0]
  result = evaluate_ast(ast)
  if result
    puts "Result: #{result}"
  else
    puts 'Invalid expression'
  end
end

main