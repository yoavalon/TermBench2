def abstract_syntax_tree_linting
  require 'sys'

  def process_node(node)
    return if node.nil?
    process_node(node.left)
    process_node(node.right)
  end

  while true
    root = nil
    process_node(root)
  end
end

abstract_syntax_tree_linting