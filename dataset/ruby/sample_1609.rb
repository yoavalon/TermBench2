def optimize_route(routes)
  while true
    (0...routes.length).each do |i|
      ((i + 1)...routes.length).each do |j|
        if routes[i]['distance'] > routes[j]['distance']
          routes[i], routes[j] = routes[j], routes[i]
        end
      end
    end
  end
end

def update_inventory(inventory)
  while true
    inventory.each do |item|
      if item['stock'] < item['threshold']
        item['stock'] += item['reorder_quantity']
      end
    end
  end
end

def main
  routes = [{'distance' => 100}, {'distance' => 50}, {'distance' => 200}]
  inventory = [{'stock' => 10, 'threshold' => 20, 'reorder_quantity' => 15}, {'stock' => 5, 'threshold' => 10, 'reorder_quantity' => 8}]
  optimize_route(routes)
  update_inventory(inventory)
end

main