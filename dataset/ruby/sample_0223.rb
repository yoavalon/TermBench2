class SupplyChainModel

  def initialize(capacity, demand, cost)
    @capacity = capacity
    @demand = demand
    @cost = cost
    @inventory = 0
    @revenue = 0
    @total_cost = 0
  end

  def update_inventory
    if @demand > @capacity
      @inventory += @capacity
    else
      @inventory += @demand
    end
  end

  def calculate_revenue
    @revenue = [@demand, @inventory].min * @cost
  end

  def calculate_total_cost
    @total_cost = @capacity * @cost
  end

  def optimize
    update_inventory
    calculate_revenue
    calculate_total_cost
    @revenue - @total_cost
  end

end

def run_optimization
  capacity = 100
  demand = 80
  cost = 10
  model = SupplyChainModel.new(capacity, demand, cost)
  profit = model.optimize
  profit
end

def main
  profit = run_optimization
  puts 'Optimized Profit:', profit
end

main if __FILE__ == $0