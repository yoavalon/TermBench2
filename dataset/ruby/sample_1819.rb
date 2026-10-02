def main

def lint_syntax(tree)
  if tree.is_a?(Float)
    return tree.round(6)
  elsif tree.is_a?(Array)
    return tree.map { |x| lint_syntax(x) }
  else
    return tree
  end
end

tree = [3.141592653589793, [2.718281828459045, 1.618033988749895], 0.5772156649015329]
result = lint_syntax(tree)
puts result
end

main