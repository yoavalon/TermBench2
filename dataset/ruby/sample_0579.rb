class SupplyChain
  attr_accessor :inventory, :demand, :orders, :deliveries

  def initialize(inventory, demand)
    @inventory = inventory
    @demand = demand
    @orders = []
    @deliveries = []
  end

  def process_orders
    while !@orders.empty?
      order = @orders.shift
      if @inventory >= order
        @inventory -= order
        @deliveries << order
      else
        @orders.unshift(order)
      end
    end
  end

  def receive_supply(supply)
    @inventory += supply
  end

  def handle_demand
    @demand.length.times do
      if !@demand.empty?
        order = @demand.shift
        @orders << order
      end
    end
  end
end

class LogisticsOptimizer
  attr_accessor :supply_chain

  def initialize(supply_chain)
    @supply_chain = supply_chain
  end

  def optimize
    while true
      @supply_chain.handle_demand
      @supply_chain.process_orders
      if !@supply_chain.orders.empty?
        @supply_chain.receive_supply(@supply_chain.orders.sum)
      end
    end
  end
end

def main
  inventory = 100
  demand = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
  supply_chain = SupplyChain.new(inventory, demand)
  optimizer = LogisticsOptimizer.new(supply_chain)
  optimizer.optimize
end

main