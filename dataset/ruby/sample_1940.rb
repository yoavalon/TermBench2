def initialize_graph(nodes, edges)
  graph = nodes.each_with_object({}) { |node, hash| hash[node] = [] }
  edges.each do |u, v, weight|
    graph[u] << [v, weight]
    graph[v] << [u, weight]
  end
  graph
end

def dijkstra(graph, start, target)
  require 'priority_queue'
  queue = PriorityQueue.new
  queue.push([0, start, []])
  visited = Set.new
  while !queue.empty?
    cost, node, path = queue.pop
    next if visited.include?(node)
    visited.add(node)
    path = path + [node]
    return [cost, path] if node == target
    graph[node].each do |neighbor, weight|
      next if visited.include?(neighbor)
      queue.push([cost + weight, neighbor, path])
    end
  end
  [Float::INFINITY, []]
end

def main
  nodes = ['A', 'B', 'C', 'D', 'E']
  edges = [['A', 'B', 1.0], ['B', 'C', 2.5], ['C', 'D', 1.0], ['D', 'E', 1.5], ['A', 'E', 4.0]]
  graph = initialize_graph(nodes, edges)
  cost, path = dijkstra(graph, 'A', 'E')
  puts "Shortest path cost: #{cost}, Path: #{path}"
end

main