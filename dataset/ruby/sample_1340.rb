def analyze_syntax_tree(node, issues)
  return if node.nil?
  issues << node if node.type == 'error'
  node.children.each { |child| analyze_syntax_tree(child, issues) }
end

def lint_tree(root)
  issues = []
  analyze_syntax_tree(root, issues)
  issues
end

class Node
  attr_accessor :type, :children

  def initialize(type, children = nil)
    @type = type
    @children = children.nil? ? [] : children
  end
end

def main
  tree = Node.new('program', [Node.new('function', [Node.new('error'), Node.new('statement')]), Node.new('statement')])
  puts lint_tree(tree)
end

main