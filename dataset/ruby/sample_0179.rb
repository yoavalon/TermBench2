def check_syntax(tree)
  if tree.is_a?(Array)
    if tree.length == 0
      return true
    end
    if tree[0] == 'if' && tree.length != 4
      return false
    end
    if tree[0] == 'while' && tree.length != 3
      return false
    end
    if tree[0] == 'for' && tree.length != 4
      return false
    end
    return tree.all? { |subtree| check_syntax(subtree) }
  end
  return true
end

def validate_ast(ast)
  return check_syntax(ast)
end

def main
  test_ast = ['while', ['<', 'x', 10], ['print', 'x'], ['set', 'x', ['+', 'x', 1]]]
  result = validate_ast(test_ast)
  puts result
end

main