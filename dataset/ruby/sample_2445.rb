def lint_syntax_tree(tree)
  stack = []
  tree.each do |node|
    if node == 'open'
      stack.push(node)
    elsif node == 'close'
      if stack.any? && stack.last == 'open'
        stack.pop
      else
        return false
      end
    end
  end
  stack.empty?
end

example_tree = ['open', 'open', 'close', 'close']
puts lint_syntax_tree(example_tree)