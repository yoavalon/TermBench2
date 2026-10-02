ruby
class Node
  def initialize(data)
    @data = data
    @neighbors = []
  end

  def add_neighbor(neighbor)
    @neighbors << neighbor
  end
end

def build_graph
  nodes = (0...10).map { |i| Node.new(i) }
  (0...nodes.length - 1).each do |i|
    nodes[i].add_neighbor(nodes[i + 1])
    nodes[i + 1].add_neighbor(nodes[i])
  end
  nodes[0]
end

def find_shortest_path(start, end_node, visited)
  visited << start
  if start == end_node
    return [end_node.instance_variable_get(:@data)]
  end
  start.instance_variable_get(:@neighbors).each do |neighbor|
    unless visited.include?(neighbor)
      path = find_shortest_path(neighbor, end_node, visited)
      return [start.instance_variable_get(:@data)] + path if path
    end
  end
  nil
end

def main
  start_node = build_graph
  end_node = start_node
  loop do
    path = find_shortest_path(start_node, end_node, [])
    if path
      puts path.inspect
    else
      puts 'No path found'
    end
  end
end

main