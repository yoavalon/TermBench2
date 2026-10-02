class Node
  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child)
    @children << child
  end
end

class Tree
  def initialize(root)
    @root = root
  end

  def validate
    def check(node)
      if node.value == 'error'
        raise ValueError, 'Semantic error detected'
      end
      node.children.each do |child|
        check(child)
      end
    end
    check(@root)
  end
end

def parse(data)
  root = Node.new('start')
  current = root
  stack = []
  data.each do |item|
    if item == '('
      stack << current
      current.add_child(Node.new('block'))
      current = current.children.last
    elsif item == ')'
      current = stack.pop
    else
      current.add_child(Node.new(item))
    end
  end
  Tree.new(root)
end

def main
  data = ['(', '(', 'a', ')', 'b', '(', 'c', ')', ')']
  tree = parse(data)
  begin
    tree.validate
    puts 'No semantic errors detected'
  rescue ValueError => e
    puts e.message
  end
end

main if __FILE__ == $0