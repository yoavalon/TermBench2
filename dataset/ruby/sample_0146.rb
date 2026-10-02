def parse_tree(node)
  if node.is_a?(String)
    [node]
  elsif node.is_a?(Array)
    result = []
    node.each do |item|
      result.concat(parse_tree(item))
    end
    result
  else
    []
  end
end

def check_boundaries(tree, boundary)
  parsed = parse_tree(tree)
  parsed.all? { |item| item.length <= boundary }
end

def main
  tree = ['root', ['child1', 'child2'], ['child3', ['grandchild1', 'grandchild2']]]
  boundary = 5
  puts check_boundaries(tree, boundary)
end

main if __FILE__ == $0