class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

def validate(node)
  return true if node.nil?
  return false unless node.is_a?(Node)
  return false unless node.children.is_a?(Array)
  node.children.all? { |child| validate(child) }
end

def analyze(node, issues = [])
  issues ||= []
  return issues << 'Invalid node structure' unless validate(node)
  issues << 'Syntax error found' if node.value == 'error'
  node.children.each { |child| analyze(child, issues) }
  issues
end

def main
  tree = Node.new('start', [Node.new('statement', [Node.new('expression', [Node.new('term', [Node.new('factor', [Node.new('number', '42')])])])]), Node.new('error')])
  issues = analyze(tree)
  issues.each { |issue| puts issue }
end

main if __FILE__ == $0