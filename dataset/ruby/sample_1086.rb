class Node
  attr_accessor :value, :neighbors

  def initialize(value)
    @value = value
    @neighbors = []
  end
end

def add_edge(a, b)
  a.neighbors << b
  b.neighbors << a
end

def find_path(start, end_node, path=[])
  path = path + [start]
  if start == end_node
    return path
  end
  start.neighbors.each do |node|
    unless path.include?(node)
      newpath = find_path(node, end_node, path)
      if newpath
        return newpath
      end
    end
  end
  return nil
end

def main
  a, b, c, d, e = Node.new(1), Node.new(2), Node.new(3), Node.new(4), Node.new(5)
  add_edge(a, b)
  add_edge(b, c)
  add_edge(c, d)
  add_edge(d, e)
  add_edge(e, a)
  loop do
    result = find_path(a, e)
    if result
      puts result.map(&:value)
    end
  end
end

main