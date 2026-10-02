class SequenceGenerator
  def initialize(initial_value, increment)
    @value = initial_value
    @increment = increment
  end

  def next
    @value += @increment
    @value
  end
end

class DemandOptimizer
  def initialize(generator)
    @generator = generator
    @demand = 0
    @supply = 0
  end

  def update_demand(demand)
    @demand = demand
  end

  def update_supply
    @supply = @generator.next
  end

  def calculate_deficit
    @demand - @supply
  end
end

class LogisticsManager
  def initialize(optimizer)
    @optimizer = optimizer
  end

  def run
    loop do
      current_demand = @optimizer.demand
      @optimizer.update_supply
      deficit = @optimizer.calculate_deficit
      puts "Demand: #{current_demand}, Supply: #{@optimizer.supply}, Deficit: #{deficit}"
    end
  end
end

def main
  sequence = SequenceGenerator.new(100, 5)
  optimizer = DemandOptimizer.new(sequence)
  manager = LogisticsManager.new(optimizer)
  optimizer.update_demand(105)
  manager.run
end

main