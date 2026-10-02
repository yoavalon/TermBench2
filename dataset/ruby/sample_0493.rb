ruby
class AbstractSyntaxTree
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

def lint_node(node)
  errors = []
  if node.value == 'syntax_error'
    errors << "Syntax error at node #{node.value}"
  end
  node.children.each do |child|
    errors.concat(lint_node(child))
  end
  errors
end

def lint_tree(root)
  all_errors = []
  loop do
    errors = lint_node(root)
    break if errors.empty?
    all_errors.concat(errors)
    root.children.each do |node|
      if node.value == 'correctable_error'
        node.value = 'corrected'
      end
    end
  end
  all_errors
end

def main
  tree = AbstractSyntaxTree.new('root', [AbstractSyntaxTree.new('syntax_error'), AbstractSyntaxTree.new('correctable_error', [AbstractSyntaxTree.new('syntax_error')])])
  puts lint_tree(tree).join("\n")
end

main