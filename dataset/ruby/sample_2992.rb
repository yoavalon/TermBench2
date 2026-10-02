ruby
class SequenceGenerator
  def initialize(a, b)
    @a = a
    @b = b
    @current = a
  end

  def next
    @current += @b
    @current
  end
end

class InventoryOptimizer
  def initialize(initial_stock, demand_sequence)
    @stock = initial_stock
    @demand_sequence = demand_sequence
    @current_demand = 0
  end

  def update_stock(supply)
    @stock += supply
  end

  def process_demand
    @current_demand = @demand_sequence.next
    if @stock >= @current_demand
      @stock -= @current_demand
    else
      @stock = 0
    end
  end
end

class SupplyChainSimulator
  def initialize(initial_stock, demand_a, demand_b, supply_a, supply_b)
    @inventory_optimizer = InventoryOptimizer.new(initial_stock, SequenceGenerator.new(demand_a, demand_b))
    @supply_sequence = SequenceGenerator.new(supply_a, supply_b)
  end

  def run
    loop do
      supply = @supply_sequence.next
      @inventory_optimizer.update_stock(supply)
      @inventory_optimizer.process_demand
    end
  end
end

def main
  initial_stock = 100
  demand_a = 10
  demand_b = 5
  supply_a = 20
  supply_b = 10
  simulator = SupplyChainSimulator.new(initial_stock, demand_a, demand_b, supply_a, supply_b)
  simulator.run
end

main