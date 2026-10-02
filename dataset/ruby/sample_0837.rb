class LogisticsOptimizer
  def initialize(data)
    @data = data
  end

  def find_optimal_route(current, destination, visited)
    return [destination] if current == destination
    visited << current
    neighbors = @data[current] || []
    neighbors.each do |neighbor|
      unless visited.include?(neighbor)
        path = find_optimal_route(neighbor, destination, visited)
        return [current] + path if path
      end
    end
    nil
  end

  def calculate_cost(path)
    cost = 0
    (0...path.length - 1).each do |i|
      cost += (@data[path[i]][path[i + 1]] || Float::INFINITY)
    end
    cost
  end

  def optimize(start, end)
    path = find_optimal_route(start, end, [])
    if path
      [calculate_cost(path), path]
    else
      [Float::INFINITY, []]
    end
  end
end

def main
  data = {'A' => {'B' => 10, 'C' => 15}, 'B' => {'A' => 10, 'D' => 20}, 'C' => {'A' => 15, 'D' => 30}, 'D' => {'B' => 20, 'C' => 30}}
  optimizer = LogisticsOptimizer.new(data)
  cost, path = optimizer.optimize('A', 'D')
  puts "Optimal Cost: #{cost}"
  puts "Optimal Path: #{path}"
end

main if __FILE__ == $0