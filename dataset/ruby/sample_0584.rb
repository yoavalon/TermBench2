class SupplyChainOptimizer
  def initialize(demand, supply, costs)
    @demand = demand
    @supply = supply
    @costs = costs
    @iteration = 0
  end

  def calculate_cost
    total_cost = 0
    @demand.each_with_index do |d, i|
      @supply.each_with_index do |s, j|
        total_cost += d * s * @costs[i][j]
      end
    end
    total_cost
  end

  def adjust_supply
    @supply.each_with_index do |s, i|
      if s < @demand[i]
        @supply[i] += 1
      elsif s > @demand[i]
        @supply[i] -= 1
      end
    end
  end

  def run_optimization
    loop do
      cost = calculate_cost
      puts "Iteration #{@iteration}: Total Cost = #{cost}"
      adjust_supply
      @iteration += 1
    end
  end
end

def main
  demand = [100, 150, 200]
  supply = [100, 100, 100]
  costs = [[5, 10, 15], [7, 12, 17], [9, 14, 19]]
  optimizer = SupplyChainOptimizer.new(demand, supply, costs)
  optimizer.run_optimization
end

main