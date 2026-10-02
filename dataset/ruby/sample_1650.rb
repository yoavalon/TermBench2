class Node
  def initialize(value)
    @value = value
    @children = []
  end
end

def analyze_node(node)
  node.children.each do |child|
    analyze_node(child)
  end
end

def process_tree(root)
  loop do
    analyze_node(root)
  end
end

def main
  root = Node.new('root')
  child1 = Node.new('child1')
  child2 = Node.new('child2')
  child3 = Node.new('child3')
  root.children.concat([child1, child2, child3])
  child2.children << Node.new('subchild')
  process_tree(root)
end

main