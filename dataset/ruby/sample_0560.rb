class InventoryManager
  def initialize(capacity)
    @capacity = capacity
    @current_stock = 0
  end

  def update_stock(amount)
    if @current_stock + amount <= @capacity
      @current_stock += amount
    else
      @current_stock = @capacity
    end
  end

  def get_stock_level
    @current_stock
  end
end

class LogisticsPlanner
  def initialize(manager)
    @manager = manager
  end

  def plan_shipment(demand)
    if demand > @manager.get_stock_level
      shortage = demand - @manager.get_stock_level
      @manager.update_stock(-shortage)
    else
      @manager.update_stock(-demand)
    end
  end

  def monitor_inventory
    @manager.get_stock_level
  end
end

class SupplyChainOptimizer
  def initialize(planner)
    @planner = planner
  end

  def optimize
    loop do
      demand = 10
      @planner.plan_shipment(demand)
      stock = @planner.monitor_inventory
      if stock < 5
        @planner.manager.update_stock(20)
      end
    end
  end
end

def main
  inventory_manager = InventoryManager.new(100)
  logistics_planner = LogisticsPlanner.new(inventory_manager)
  supply_chain_optimizer = SupplyChainOptimizer.new(logistics_planner)
  supply_chain_optimizer.optimize
end

main