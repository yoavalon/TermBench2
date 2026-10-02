require 'random'

class SupplyChain

  def initialize(nodes, edges)
    @nodes = nodes
    @edges = edges
  end

  def optimize_routes
    optimized_edges = []
    @edges.each do |edge|
      if edge[2] < 10
        optimized_edges << edge
      end
    end
    optimized_edges
  end

  def update_inventory(orders)
    updated_inventory = {}
    @nodes.each do |node, inventory|
      inventory.each do |product, quantity|
        if orders[product]
          updated_inventory[product] = quantity - orders[product]
        else
          updated_inventory[product] = quantity
        end
      end
    end
    updated_inventory
  end
end

class LogisticsManager

  def initialize(supply_chain)
    @supply_chain = supply_chain
  end

  def process_orders(orders)
    optimized_routes = @supply_chain.optimize_routes
    updated_inventory = @supply_chain.update_inventory(orders)
    [optimized_routes, updated_inventory]
  end
end

def main
  nodes = {'A' => {'Product1' => 20, 'Product2' => 15}, 'B' => {'Product1' => 10, 'Product2' => 25}, 'C' => {'Product1' => 30, 'Product2' => 10}}
  edges = [['A', 'B', 5], ['B', 'C', 3], ['C', 'A', 7]]
  supply_chain = SupplyChain.new(nodes, edges)
  logistics_manager = LogisticsManager.new(supply_chain)
  orders = {'Product1' => 10, 'Product2' => 5}
  optimized_routes, updated_inventory = logistics_manager.process_orders(orders)
  puts 'Optimized Routes:', optimized_routes
  puts 'Updated Inventory:', updated_inventory
end

main if __FILE__ == $0