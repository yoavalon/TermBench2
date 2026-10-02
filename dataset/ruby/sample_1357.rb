require 'matrix'

def optimize_routes(data)
  costs = Matrix.rows(data)
  optimal_indices = costs.min_by_row.map(&:index)
  optimal_indices.to_a
end

def update_inventory(routes, inventory)
  routes.each do |route|
    inventory[route] -= 1
  end
  inventory
end

def main
  data = [[5, 3, 8], [2, 6, 4], [7, 1, 9]]
  inventory = [10, 10, 10]
  routes = optimize_routes(data)
  updated_inventory = update_inventory(routes, inventory)
  puts updated_inventory.inspect
end

main