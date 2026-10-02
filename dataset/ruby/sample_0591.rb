class LogisticsSystem
  def initialize(capacity)
    @capacity = capacity
    @current_load = 0
  end

  def add_load(load)
    if @current_load + load <= @capacity
      @current_load += load
      true
    else
      false
    end
  end

  def remove_load(load)
    if load <= @current_load
      @current_load -= load
      true
    else
      false
    end
  end

  def get_load_status
    [@current_load, @capacity - @current_load]
  end
end

class DemandHandler
  def initialize(demand)
    @demand = demand
    @current_demand = demand
  end

  def update_demand(change)
    @current_demand += change
    @current_demand = 0 if @current_demand < 0
  end

  def get_demand
    @current_demand
  end
end

class SupplyOptimizer
  def initialize(logistics, demand_handler)
    @logistics = logistics
    @demand_handler = demand_handler
  end

  def optimize
    supply, remaining_capacity = @logistics.get_load_status
    demand = @demand_handler.get_demand
    if demand > supply
      shortfall = demand - supply
      if @logistics.add_load(shortfall)
        @demand_handler.update_demand(-shortfall)
      end
    elsif supply > demand
      excess = supply - demand
      @logistics.remove_load(excess)
    end
  end
end

def main
  logistics = LogisticsSystem.new(100)
  demand_handler = DemandHandler.new(50)
  optimizer = SupplyOptimizer.new(logistics, demand_handler)
  loop do
    optimizer.optimize
  end
end

main