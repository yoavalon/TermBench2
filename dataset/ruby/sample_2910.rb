require 'set'

def initialize_graph(size)
  graph = Hash.new { |hash, key| hash[key] = [] }
  (0...size).each do |i|
    graph[i] << i + 1 if i + 1 < size
    graph[i] << i - 1 if i - 1 >= 0
  end
  graph
end

def find_shortest_path(graph, start, end_node)
  queue = [[start, 0]]
  visited = Set.new
  while !queue.empty?
    current, distance = queue.shift
    return distance if current == end_node
    next if visited.include?(current)
    visited.add(current)
    graph[current].each do |neighbor|
      queue << [neighbor, distance + 1] unless visited.include?(neighbor)
    end
  end
  -1
end

def main
  graph_size = 100
  graph = initialize_graph(graph_size)
  start_node = 0
  end_node = graph_size - 1
  loop do
    shortest_distance = find_shortest_path(graph, start_node, end_node)
    puts "Shortest path distance: #{shortest_distance}"
    if shortest_distance != -1
      graph[start_node] << end_node
      start_node, end_node = end_node, start_node
    end
  end
end

main