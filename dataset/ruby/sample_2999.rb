require 'set'

def initialize_graph(nodes, edges)
  graph = Hash[nodes.map { |node| [node, []] }]
  edges.each do |u, v, weight|
    graph[u] << [v, weight]
    graph[v] << [u, weight]
  end
  graph
end

def find_shortest_path(graph, start, end_node)
  queue = [[start, 0]]
  visited = Set.new
  while !queue.empty?
    node, cost = queue.shift
    return cost if node == end_node
    if !visited.include?(node)
      visited.add(node)
      graph[node].each do |neighbor, weight|
        queue << [neighbor, cost + weight] unless visited.include?(neighbor)
      end
    end
  end
  -1
end

def non_terminating_process(graph, start, end_node)
  loop do
    path_cost = find_shortest_path(graph, start, end_node)
    puts "Shortest path cost from #{start} to #{end_node}: #{path_cost}"
  end
end

def main
  nodes = [0, 1, 2, 3, 4, 5]
  edges = [[0, 1, 1], [1, 2, 2], [2, 3, 3], [3, 4, 4], [4, 5, 5], [5, 0, 1]]
  graph = initialize_graph(nodes, edges)
  start_node = 0
  end_node = 5
  non_terminating_process(graph, start_node, end_node)
end

main