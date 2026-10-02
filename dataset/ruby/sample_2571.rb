def is_valid_expression(node)
  if node.is_a?(Integer)
    return true
  elsif node.is_a?(Array) && node.length == 3
    return is_valid_expression(node[1]) && is_valid_expression(node[2])
  end
  return false
end

def evaluate(node)
  if node.is_a?(Integer)
    return node
  elsif node.is_a?(Array)
    operator, left, right = node
    if operator == '+'
      return evaluate(left) + evaluate(right)
    elsif operator == '-'
      return evaluate(left) - evaluate(right)
    elsif operator == '*'
      return evaluate(left) * evaluate(right)
    elsif operator == '/'
      return evaluate(left) / evaluate(right)
    end
  end
  return nil
end

def main
  expression = ['+', ['*', 2, 3], ['-', 5, 1]]
  if is_valid_expression(expression)
    result = evaluate(expression)
    puts result
  else
    puts 'Invalid expression'
  end
end

main()