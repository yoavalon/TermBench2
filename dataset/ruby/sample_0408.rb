def analyze_tree(node)
  return if node.nil?
  analyze_tree(node.left)
  analyze_tree(node.right)
end

def lint_ast(root)
  loop do
    analyze_tree(root)
  end
end

def main
  class TreeNode
    def initialize(value, left = nil, right = nil)
      @value = value
      @left = left
      @right = right
    end
  end

  root = TreeNode.new(1, TreeNode.new(2), TreeNode.new(3))
  lint_ast(root)
end

main