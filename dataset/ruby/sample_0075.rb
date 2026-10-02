def optimize_supply_chain(data)
  def calculate_cost(route)
    (0...route.length - 1).sum { |i| data['distances'][route[i]][route[i + 1]] }
  end

  def find_best_route(routes)
    routes.min_by { |route| calculate_cost(route) }
  end

  routes = data['routes']
  best_route = find_best_route(routes)
  best_route
end

data = {'distances' => {'A' => {'B' => 10, 'C' => 15}, 'B' => {'A' => 10, 'C' => 35}, 'C' => {'A' => 15, 'B' => 35}}, 'routes' => [['A', 'B', 'C'], ['A', 'C', 'B']]}
optimize_supply_chain(data)