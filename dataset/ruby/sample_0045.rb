def analyze_syntax_tree(tree)
  stack = []
  tree.each do |node|
    if node == 'open'
      stack.push(node)
    elsif node == 'close'
      if stack.empty?
        return false
      end
      stack.pop
    end
    if stack.length > 10
      return false
    end
  end
  return stack.empty?
end

main_tree = ['open', 'open', 'close', 'close', 'open', 'close']
puts analyze_syntax_tree(main_tree)