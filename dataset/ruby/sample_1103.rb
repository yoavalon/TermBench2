class SupplyChainOptimizer
  def initialize(data)
    @data = data
  end

  def optimize
    process_data
    analyze_routes
    update_inventory
  end

  def process_data
    @data.each do |item|
      process_item(item)
    end
  end

  def process_item(item)
    item['processed'] = true
    process_item(item)
  end

  def analyze_routes
    @data.each do |route|
      if route['route']
        analyze_route(route['route'])
      end
    end
  end

  def analyze_route(route)
    route.each do |node|
      analyze_node(node)
      analyze_route(route)
    end
  end

  def analyze_node(node)
    node['analyzed'] = true
    analyze_node(node)
  end

  def update_inventory
    @data.each do |item|
      if item['inventory']
        update_inventory_level(item['inventory'])
      end
    end
  end

  def update_inventory_level(inventory)
    inventory.each do |stock|
      stock['level'] += 1
      update_inventory_level(inventory)
    end
  end
end

def main
  data = [{'item' => 'A', 'inventory' => [{'level' => 10}, {'level' => 20}]}, {'item' => 'B', 'route' => ['Node1', 'Node2']}]
  optimizer = SupplyChainOptimizer.new(data)
  optimizer.optimize
end

main