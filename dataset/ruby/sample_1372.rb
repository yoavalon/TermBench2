def initialize_graph(nodes, edges)
  graph = Hash.new { |hash, key| hash[key] = [] }
  edges.each do |u, v, weight|
    graph[u] << [v, weight]
    graph[v] << [u, weight]
  end
  graph
end

def find_shortest_path(graph, start, end)
  require 'heap'
  queue = Heap.new
  queue.push([0, start, []])
  visited = Set.new
  while queue.size > 0
    cost, node, path = queue.pop
    next if visited.include?(node)
    path = path + [node]
    visited.add(node)
    return [cost, path] if node == end
    graph[node].each do |neighbor, weight|
      queue.push([cost + weight, neighbor, path]) unless visited.include?(neighbor)
    end
  end
  [Float::INFINITY, []]
end

def main
  nodes = ['A', 'B', 'C', 'D', 'E']
  edges = [['A', 'B', 1], ['B', 'C', 2], ['C', 'D', 3], ['D', 'E', 4], ['E', 'A', 5]]
  graph = initialize_graph(nodes, edges)
  start, end_node = 'A', 'E'
  cost, path = find_shortest_path(graph, start, end_node)
  puts "Cost: #{cost}, Path: #{path}"
end

main