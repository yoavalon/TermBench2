class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

def validate(node, seen = nil)
  seen ||= Set.new
  return false if seen.include?(node)
  seen.add(node)
  @children.each do |child|
    return false unless validate(child, seen)
  end
  true
end

def check_tree(root)
  validate(root) && root.children.length <= 2
end

def main
  root = Node.new(0, [Node.new(1), Node.new(2, [Node.new(3), Node.new(4)])])
  puts check_tree(root)
end

main if __FILE__ == $0