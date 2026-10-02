class Node
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end
end

def evaluate(node)
  if node.value.is_a?(Float)
    format('%.5f', node.value).to_f
  else
    node.value
  end
end

def process_tree(root)
  return unless root
  root.value = evaluate(root)
  root.children.each { |child| process_tree(child) }
end

def main
  tree = Node.new(3.1415926535, [Node.new(2.7182818284), Node.new(1.4142135623)])
  process_tree(tree)
  puts "#{tree.value} #{tree.children[0].value} #{tree.children[1].value}"
end

main if __FILE__ == $0