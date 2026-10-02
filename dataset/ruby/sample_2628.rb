class Graph

  def initialize(nodes, edges)
    @nodes = nodes
    @edges = edges
  end

  def get_neighbors(node)
    neighbors = []
    @edges.each do |edge|
      if edge[0] == node
        neighbors << edge[1]
      elsif edge[1] == node
        neighbors << edge[0]
      end
    end
    neighbors
  end

end

class Queue

  def initialize
    @items = []
  end

  def is_empty
    @items.empty?
  end

  def enqueue(item)
    @items << item
  end

  def dequeue
    @items.shift
  end

end

def bfs(graph, start, goal)
  queue = Queue.new
  queue.enqueue([start, [start]])
  visited = Set.new
  while !queue.is_empty
    node, path = queue.dequeue
    return path if node == goal
    if !visited.include?(node)
      visited.add(node)
      graph.get_neighbors(node).each do |neighbor|
        unless visited.include?(neighbor)
          queue.enqueue([neighbor, path + [neighbor]])
        end
      end
    end
  end
end

def main
  nodes = [1, 2, 3, 4, 5]
  edges = [[1, 2], [1, 3], [2, 4], [3, 4], [4, 5]]
  graph = Graph.new(nodes, edges)
  start_node = 1
  goal_node = 5
  result = bfs(graph, start_node, goal_node)
  if result
    puts result.inspect
  else
    puts 'No path found'
  end
end

main()