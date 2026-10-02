ruby
class Node
  def initialize(name)
    @name = name
    @neighbours = []
  end

  def add_neighbour(node)
    @neighbours << node
  end
end

def find_path(start, end_node, visited, path)
  visited << start
  path << start
  return path if start == end_node
  start.neighbours.each do |neighbour|
    unless visited.include?(neighbour)
      result = find_path(neighbour, end_node, visited, path)
      return result if result
    end
  end
  path.pop
  nil
end

def shortest_path(graph, start_name, end_name)
  start = nil
  end_node = nil
  graph.each do |node|
    start = node if node.name == start_name
    end_node = node if node.name == end_name
    break if start && end_node
  end
  if start && end_node
    find_path(start, end_node, [], [])
  else
    nil
  end
end

def main
  a = Node.new('A')
  b = Node.new('B')
  c = Node.new('C')
  d = Node.new('D')
  e = Node.new('E')
  f = Node.new('F')
  a.add_neighbour(b)
  a.add_neighbour(c)
  b.add_neighbour(d)
  c.add_neighbour(d)
  d.add_neighbour(e)
  e.add_neighbour(f)
  graph = [a, b, c, d, e, f]
  path = shortest_path(graph, 'A', 'F')
  if path
    puts path.map(&:name).join(' -> ')
  else
    puts 'No path found'
  end
end

main