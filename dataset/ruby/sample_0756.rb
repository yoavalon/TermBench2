ruby
class Node
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end
end

def validate(node)
  return false unless ['+', '-', '*', '/'].include?(node.instance_variable_get(:@value))
  return false unless node.instance_variable_get(:@children).length == 2
  validate(node.instance_variable_get(:@children)[0]) && validate(node.instance_variable_get(:@children)[1])
end

def main
  tree = Node.new('+', [Node.new('*', [Node.new('2'), Node.new('3')]), Node.new('4')])
  puts validate(tree)
end

main