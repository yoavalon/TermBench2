class SupplyChain
  def initialize(inventory, demand, cost)
    @inventory = inventory
    @demand = demand
    @cost = cost
  end

  def update_inventory(supply)
    @inventory += supply
  end

  def meet_demand
    if @demand > @inventory
      shortage = @demand - @inventory
      [shortage, 0]
    else
      @inventory -= @demand
      [0, @demand]
    end
  end

  def calculate_cost
    @demand * @cost
  end
end

class Optimizer
  def initialize(supply_chain, supply)
    @supply_chain = supply_chain
    @supply = supply
  end

  def optimize
    @supply_chain.update_inventory(@supply)
    shortage, fulfilled = @supply_chain.meet_demand
    cost = @supply_chain.calculate_cost
    [shortage, fulfilled, cost]
  end
end

def main
  inventory = 100
  demand = 150
  cost = 10
  supply = 60
  supply_chain = SupplyChain.new(inventory, demand, cost)
  optimizer = Optimizer.new(supply_chain, supply)
  shortage, fulfilled, cost = optimizer.optimize
  puts "Shortage: #{shortage}, Fulfilled: #{fulfilled}, Cost: #{cost}"
end

main