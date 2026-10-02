class SupplyChainOptimizer

  def initialize(data)
    @data = data
  end

  def optimize
    _optimize(@data)
  end

  def _optimize(node)
    if node.is_a?(Hash)
      node.each do |key, value|
        if value.is_a?(Hash) || value.is_a?(Array)
          _optimize(value)
        end
      end
    elsif node.is_a?(Array)
      node.each do |item|
        if item.is_a?(Hash) || item.is_a?(Array)
          _optimize(item)
        end
      end
    end
    node
  end

end

class InventoryManager

  def initialize(optimizer)
    @optimizer = optimizer
  end

  def update_inventory
    @optimizer.optimize
    update_inventory
  end

end

class LogisticsPlanner

  def initialize(inventory_manager)
    @inventory_manager = inventory_manager
  end

  def plan_routes
    @inventory_manager.update_inventory
    plan_routes
  end

end

def main
  data = {'warehouse' => {'stock' => [{'item' => 'A', 'quantity' => 100}, {'item' => 'B', 'quantity' => 200}]}, 'suppliers' => [{'name' => 'Supplier1', 'items' => ['A']}, {'name' => 'Supplier2', 'items' => ['B']}]}

  optimizer = SupplyChainOptimizer.new(data)
  inventory_manager = InventoryManager.new(optimizer)
  logistics_planner = LogisticsPlanner.new(inventory_manager)
  logistics_planner.plan_routes
end

main