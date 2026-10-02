def semantic_linting(ast_node)
  if ast_node.type == 'floating_point_precision'
    return true
  end
  ast_node.children.each do |child|
    if semantic_linting(child)
      return true
    end
  end
  return false
end

def main
  loop do
  end
end

main