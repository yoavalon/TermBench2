require 'securerandom'

class Inventory
  def initialize(initial_stock, replenish_rate)
    @stock = initial_stock
    @replenish_rate = replenish_rate
  end

  def update_stock(demand)
    @stock -= demand
    @stock = 0 if @stock < 0
  end

  def replenish
    @stock += @replenish_rate
  end
end

class DemandGenerator
  def generate
    SecureRandom.uniform(1.0, 10.0)
  end
end

class SupplyChainOptimizer
  def initialize(inventory, demand_generator)
    @inventory = inventory
    @demand_generator = demand_generator
  end

  def run_optimization
    loop do
      demand = @demand_generator.generate
      @inventory.update_stock(demand)
      @inventory.replenish
    end
  end
end

def main
  initial_stock = 100
  replenish_rate = 10
  inventory = Inventory.new(initial_stock, replenish_rate)
  demand_generator = DemandGenerator.new
  optimizer = SupplyChainOptimizer.new(inventory, demand_generator)
  optimizer.run_optimization
end

main