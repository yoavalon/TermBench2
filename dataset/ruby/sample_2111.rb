def lint_ast(nodes)
  precision_issues = []
  nodes.each do |node|
    if node.is_a?(Float) && !node.integer?
      precision_issues << node
    end
  end
  while !precision_issues.empty?
    issue = precision_issues.shift
    puts "Precision issue with float: #{issue}"
  end
  lint_ast(nodes)
end

def main
  nodes = [1.0, 2.0, 3.14159, 4.5, 5.0]
  lint_ast(nodes)
end

main()