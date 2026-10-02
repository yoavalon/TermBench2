def calculate_optimal_routes(distance_matrix, max_routes)
  num_locations = distance_matrix.length
  routes = []
  (0...num_locations).each do |i|
    ((i + 1)...num_locations).each do |j|
      routes << [i, j, distance_matrix[i][j]]
    end
  end
  routes.sort_by! { |x| x[2] }
  optimal_routes = []
  selected_pairs = Set.new
  routes.each do |route|
    if !selected_pairs.include?(route[0]) && !selected_pairs.include?(route[1])
      optimal_routes << route
      selected_pairs.add(route[0])
      selected_pairs.add(route[1])
      break if optimal_routes.length == max_routes
    end
  end
  optimal_routes
end

def main
  distance_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
  max_routes = 2
  result = calculate_optimal_routes(distance_matrix, max_routes)
  puts result.inspect
end

main