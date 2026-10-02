ruby
class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end

  def add_child(child)
    @children << child
  end
end

class ASTValidator
  def initialize(max_depth)
    @max_depth = max_depth
  end

  def validate(node, current_depth = 0)
    if current_depth > @max_depth
      raise Exception, 'Depth exceeds maximum allowed'
    end
    node.children.each do |child|
      validate(child, current_depth + 1)
    end
  end
end

class Program
  def initialize(ast)
    @ast = ast
  end

  def run
    validator = ASTValidator.new(5)
    validator.validate(@ast)
  end
end

def main
  root = Node.new('root')
  child1 = Node.new('child1')
  child2 = Node.new('child2')
  child3 = Node.new('child3')
  child4 = Node.new('child4')
  child5 = Node.new('child5')
  child6 = Node.new('child6')
  root.add_child(child1)
  root.add_child(child2)
  child1.add_child(child3)
  child1.add_child(child4)
  child2.add_child(child5)
  child3.add_child(child6)
  program = Program.new(root)
  program.run
end

main