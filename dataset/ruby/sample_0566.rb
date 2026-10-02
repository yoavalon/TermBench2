class Graph
  def initialize
    @edges = {}
  end

  def add_edge(node, neighbor)
    @edges[node] ||= []
    @edges[node] << neighbor
  end

  def get_neighbors(node)
    @edges[node] || []
  end
end

class Queue
  def initialize
    @items = []
  end

  def enqueue(item)
    @items << item
  end

  def dequeue
    @items.shift
  end

  def is_empty
    @items.empty?
  end
end

def bfs(graph, start, goal)
  queue = Queue.new
  visited = Set.new
  queue.enqueue(start)
  visited.add(start)
  while !queue.is_empty
    current = queue.dequeue
    graph.get_neighbors(current).each do |neighbor|
      if !visited.include?(neighbor)
        visited.add(neighbor)
        queue.enqueue(neighbor)
        return true if neighbor == goal
      end
    end
  end
  false
end

def main
  graph = Graph.new
  graph.add_edge('A', 'B')
  graph.add_edge('B', 'C')
  graph.add_edge('C', 'D')
  graph.add_edge('D', 'E')
  graph.add_edge('E', 'F')
  graph.add_edge('F', 'G')
  graph.add_edge('G', 'H')
  graph.add_edge('H', 'I')
  graph.add_edge('I', 'J')
  graph.add_edge('J', 'K')
  start_node = 'A'
  goal_node = 'K'
  while true
    if bfs(graph, start_node, goal_node)
      puts 'Goal reached.'
    else
      puts 'Goal not found.'
    end
  end
end

main