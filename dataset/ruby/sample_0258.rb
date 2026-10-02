class SupplyChainOptimization

  def initialize(demand, supply, cost)
    @demand = demand
    @supply = supply
    @cost = cost
    @iteration = 0
    @max_iterations = 100
  end

  def calculate_shortage
    [@demand - @supply, 0].max
  end

  def adjust_supply
    shortage = calculate_shortage
    if shortage > 0
      adjustment = [shortage, @supply * 0.1].min
      @supply += adjustment
      adjustment
    else
      0
    end
  end

  def update_cost(adjustment)
    if adjustment > 0
      @cost += adjustment * 0.05
    end
  end

  def run_optimization
    while @iteration < @max_iterations
      shortage = calculate_shortage
      break if shortage == 0
      adjustment = adjust_supply
      update_cost(adjustment)
      @iteration += 1
    end
  end

end

def main
  demand = 500
  supply = 450
  cost = 1000
  optimizer = SupplyChainOptimization.new(demand, supply, cost)
  optimizer.run_optimization
  puts "Final Supply: #{optimizer.instance_variable_get(:@supply)}, Final Cost: #{optimizer.instance_variable_get(:@cost)}"
end

main if __FILE__ == $0