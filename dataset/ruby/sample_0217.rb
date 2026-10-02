class Graph
  def initialize(nodes)
    @nodes = nodes
    @edges = {}
  end

  def add_edge(u, v, weight)
    if @edges.key?(u)
      @edges[u] << [v, weight]
    else
      @edges[u] = [[v, weight]]
    end
    if @edges.key?(v)
      @edges[v] << [u, weight]
    else
      @edges[v] = [[u, weight]]
    end
  end
end

class PriorityQueue
  def initialize
    @elements = []
  end

  def add(item, priority)
    @elements << [priority, item]
    @elements.sort!
  end

  def remove
    @elements.shift[1]
  end

  def empty?
    @elements.empty?
  end
end

def dijkstra(graph, start, end_node)
  queue = PriorityQueue.new
  queue.add(start, 0)
  came_from = {}
  cost_so_far = { start => 0 }
  while !queue.empty?
    current = queue.remove
    break if current == end_node
    graph.edges[current] && graph.edges[current].each do |neighbor, weight|
      new_cost = cost_so_far[current] + weight
      if !cost_so_far.key?(neighbor) || new_cost < cost_so_far[neighbor]
        cost_so_far[neighbor] = new_cost
        priority = new_cost
        queue.add(neighbor, priority)
        came_from[neighbor] = current
      end
    end
  end
  [came_from, cost_so_far]
end

def reconstruct_path(came_from, start, end_node)
  path = []
  current = end_node
  while current != start
    path << current
    current = came_from[current]
  end
  path << start
  path.reverse
end

def main
  nodes = ['A', 'B', 'C', 'D', 'E']
  graph = Graph.new(nodes)
  graph.add_edge('A', 'B', 1)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('C', 'D', 1)
  graph.add_edge('D', 'E', 3)
  graph.add_edge('A', 'E', 10)
  start = 'A'
  end_node = 'E'
  came_from, cost_so_far = dijkstra(graph, start, end_node)
  path = reconstruct_path(came_from, start, end_node)
  puts "Shortest path from #{start} to #{end_node}: #{path}"
  puts "Cost of the path: #{cost_so_far[end_node]}"
end

main