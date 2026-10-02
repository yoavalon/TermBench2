require 'mathn'

class SupplyChain

  def initialize(demand, supply, transport_cost, holding_cost)
    @demand = demand
    @supply = supply
    @transport_cost = transport_cost
    @holding_cost = holding_cost
    @inventory = supply
  end

  def calculate_total_cost(quantity)
    if quantity > @supply
      Float::INFINITY
    else
      transport = quantity * @transport_cost
      holding = @holding_cost * (@supply - quantity) ** 2
      transport + holding
    end
  end

  def optimize_order_quantity
    min_cost = Float::INFINITY
    optimal_quantity = 0
    (1..@supply).each do |quantity|
      cost = calculate_total_cost(quantity)
      if cost < min_cost
        min_cost = cost
        optimal_quantity = quantity
      end
    end
    optimal_quantity
  end

end

def main
  demand = 100
  supply = 150
  transport_cost = 2.5
  holding_cost = 0.1
  supply_chain = SupplyChain.new(demand, supply, transport_cost, holding_cost)
  optimal_quantity = supply_chain.optimize_order_quantity
  puts "Optimal Order Quantity: #{optimal_quantity}"
end

main if __FILE__ == $0