class SupplyChain
  def initialize(inventory, demand, cost, capacity)
    @inventory = inventory
    @demand = demand
    @cost = cost
    @capacity = capacity
  end

  def calculate_profit
    supply = [@inventory, @capacity].min
    revenue = supply * @demand
    expenses = supply * @cost
    revenue - expenses
  end

  def update_inventory
    @inventory -= [@inventory, @capacity].min
  end
end

class LogisticsOptimizer
  def initialize(supply_chain)
    @supply_chain = supply_chain
  end

  def optimize
    loop do
      profit = @supply_chain.calculate_profit
      @supply_chain.update_inventory
      if profit > 0
        @supply_chain.capacity += 1
      else
        @supply_chain.capacity -= 1
      end
    end
  end
end

def main
  initial_inventory = 1000
  demand_rate = 50
  production_cost = 10
  initial_capacity = 150
  supply_chain = SupplyChain.new(initial_inventory, demand_rate, production_cost, initial_capacity)
  optimizer = LogisticsOptimizer.new(supply_chain)
  optimizer.optimize
end

main