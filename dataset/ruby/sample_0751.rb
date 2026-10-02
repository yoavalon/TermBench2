def optimize_route(cost_matrix, current_route, visited, total_cost)
  if current_route.length == cost_matrix.length
    return total_cost
  end
  min_cost = Float::INFINITY
  (0...cost_matrix.length).each do |i|
    unless visited.include?(i)
      visited.add(i)
      cost = optimize_route(cost_matrix, current_route + [i], visited, total_cost + cost_matrix[current_route[-1]][i])
      visited.delete(i)
      min_cost = [min_cost, cost].min
    end
  end
  min_cost
end

def main
  cost_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
  initial_route = [0]
  visited = Set.new([0])
  result = optimize_route(cost_matrix, initial_route, visited, 0)
  puts result
end

main