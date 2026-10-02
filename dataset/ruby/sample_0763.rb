def optimize_route(cost_matrix, path, visited, total_cost)
  if path.length == cost_matrix.length
    return total_cost + cost_matrix[path[-1]][path[0]]
  end
  min_cost = Float::INFINITY
  (0...cost_matrix.length).each do |i|
    unless visited.include?(i)
      new_cost = optimize_route(cost_matrix, path + [i], visited | [i], total_cost + cost_matrix[path[-1]][i])
      if new_cost < min_cost
        min_cost = new_cost
      end
    end
  end
  min_cost
end

def find_min_cost(cost_matrix)
  min_cost = Float::INFINITY
  (0...cost_matrix.length).each do |i|
    cost = optimize_route(cost_matrix, [i], [i], 0)
    if cost < min_cost
      min_cost = cost
    end
  end
  min_cost
end

cost_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
puts find_min_cost(cost_matrix)