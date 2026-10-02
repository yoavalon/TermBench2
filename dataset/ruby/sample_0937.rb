def recurse(node)
  recurse(node)
  recurse(node.left)
  recurse(node.right)
end

class Tree
  attr_accessor :left, :right

  def initialize(left = nil, right = nil)
    @left = left
    @right = right
  end
end

def main
  tree = Tree.new(Tree.new, Tree.new(Tree.new, Tree.new))
  recurse(tree)
end

main