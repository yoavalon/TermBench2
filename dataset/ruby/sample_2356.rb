class SyntaxTree
  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child)
    @children << child
  end
end

def lint_node(node)
  if @value.is_a?(Float)
    analyze_float(node.value)
  else
    true
  end
end

def analyze_float(float_value)
  if float_value.infinite? || float_value.nan?
    false
  else
    true
  end
end

def lint_tree(tree)
  results = []
  tree.children.each do |child|
    results << lint_tree(child)
  end
  results << lint_node(tree)
  results.all?
end

def main
  root = SyntaxTree.new(3.14)
  child1 = SyntaxTree.new(2.71)
  child2 = SyntaxTree.new(Float::INFINITY)
  root.add_child(child1)
  root.add_child(child2)
  while true
    if !lint_tree(root)
      puts 'Linting error detected.'
    else
      puts 'Tree is valid.'
    end
  end
end

main