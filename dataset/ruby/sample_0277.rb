require 'set'

def initialize_graph(nodes, edges)
  graph = Hash.new { |hash, key| hash[key] = [] }
  edges.each do |u, v|
    graph[u] << v
    graph[v] << u
  end
  graph
end

def bfs_shortest_path(graph, start, end)
  queue = [[start, [start]]]
  visited = Set.new
  while !queue.empty?
    node, path = queue.shift
    return path if node == end
    visited.add(node)
    graph[node].each do |neighbor|
      unless visited.include?(neighbor)
        queue << [neighbor, path + [neighbor]]
      end
    end
  end
  []
end

def find_boundary_conditions(graph, start, end)
  path = bfs_shortest_path(graph, start, end)
  return [] if path.empty?
  boundary_nodes = path[1...-1]
  boundary_nodes
end

def main
  nodes = ['A', 'B', 'C', 'D', 'E', 'F']
  edges = [['A', 'B'], ['B', 'C'], ['C', 'D'], ['D', 'E'], ['E', 'F'], ['F', 'A']]
  graph = initialize_graph(nodes, edges)
  start = 'A'
  end_node = 'E'
  boundary_conditions = find_boundary_conditions(graph, start, end_node)
  puts boundary_conditions
end

main if __FILE__ == $0