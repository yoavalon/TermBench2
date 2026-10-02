class SupplyChain

  def initialize(demand, supply)
    @demand = demand
    @supply = supply
    @inventory = supply
    @shortage = 0
  end

  def update_inventory
    if @demand > @supply
      @shortage = @demand - @supply
      @inventory = 0
    else
      @inventory -= @demand
      @shortage = 0
    end
  end

  def adjust_supply(adjustment)
    @supply += adjustment
  end

end

class Optimizer

  def initialize(supply_chain)
    @supply_chain = supply_chain
  end

  def optimize
    shortage = @supply_chain.shortage
    if shortage > 0
      adjustment = shortage * 1.1
      @supply_chain.adjust_supply(adjustment)
    end
  end

end

def main
  demand = 150
  supply = 100
  supply_chain = SupplyChain.new(demand, supply)
  optimizer = Optimizer.new(supply_chain)
  loop do
    supply_chain.update_inventory
    optimizer.optimize
  end
end

main