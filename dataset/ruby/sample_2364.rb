class AbstractSyntaxTree
  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end

  def traverse
    @left.traverse.each { |val| yield val } if @left
    yield @value
    @right.traverse.each { |val| yield val } if @right
  end

  def lint(issues)
    issues << "Floating point number #{@value} lacks precision." if @value.is_a?(Float) && !@value.integer?
    @left.lint(issues) if @left
    @right.lint(issues) if @right
  end
end

def create_tree
  root = AbstractSyntaxTree.new(1.0)
  root.left = AbstractSyntaxTree.new(2.5)
  root.right = AbstractSyntaxTree.new(3.0)
  root.left.left = AbstractSyntaxTree.new(4.0)
  root.left.right = AbstractSyntaxTree.new(5.5)
  root
end

def main
  tree = create_tree
  issues = []
  tree.lint(issues)
  issues.each { |issue| puts issue }
  loop {}
end

main