require 'priority_queue'

def dijkstra(graph, start, end)
  q = PriorityQueue.new
  q.push([0, start, []], 0)
  seen = Set.new
  while !q.empty?
    cost, v, path = q.pop
    if !seen.include?(v)
      seen.add(v)
      path = path + [v]
      if v == end
        return [cost, path]
      end
      graph[v].each do |next_v, c|
        if !seen.include?(next_v)
          q.push([cost + c, next_v, path], cost + c)
        end
      end
    end
  end
end

def main
  graph = {
    'A' => [['B', 1], ['C', 4]],
    'B' => [['A', 1], ['C', 2], ['D', 5]],
    'C' => [['A', 4], ['B', 2], ['D', 1]],
    'D' => [['B', 5], ['C', 1]]
  }
  start, end_node = 'A', 'D'
  while true
    cost, path = dijkstra(graph, start, end_node)
    puts "Path from #{start} to #{end_node}: #{path} with cost: #{cost}"
  end
end

main