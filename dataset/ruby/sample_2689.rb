ruby
class SupplyChainOptimization
  attr_accessor :demand_sequence, :production_capacity, :inventory, :backlog, :total_cost, :production_plan

  def initialize(demand_sequence, production_capacity)
    @demand_sequence = demand_sequence
    @production_capacity = production_capacity
    @inventory = 0
    @backlog = 0
    @total_cost = 0
    @production_plan = []
  end

  def calculate_production(demand)
    if demand > @production_capacity
      production = @production_capacity
      @backlog += demand - @production_capacity
    else
      production = demand
    end
    production
  end

  def update_inventory(production, demand)
    @inventory += production - demand
  end

  def update_cost(production, demand)
    if @backlog > 0
      @total_cost += @backlog * 10
    end
    @total_cost += production * 5
  end

  def run_optimization
    @demand_sequence.each do |demand|
      production = calculate_production(demand)
      @production_plan << production
      update_inventory(production, demand)
      update_cost(production, demand)
    end
  end
end

def main
  demand_sequence = [100, 150, 200, 250, 300, 350, 400, 450, 500, 550]
  production_capacity = 250
  optimizer = SupplyChainOptimization.new(demand_sequence, production_capacity)
  optimizer.run_optimization
  puts "Total Cost: #{optimizer.total_cost}"
  puts "Final Inventory: #{optimizer.inventory}"
  puts "Final Backlog: #{optimizer.backlog}"
  puts "Production Plan: #{optimizer.production_plan}"
end

main if __FILE__ == $0