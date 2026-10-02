class SequenceGenerator
  def initialize(start, increment)
    @current = start
    @increment = increment
  end

  def generate(count)
    sequence = []
    count.times do
      sequence << @current
      @current += @increment
    end
    sequence
  end
end

class SupplyChainOptimizer
  def initialize(demand, supply)
    @demand = demand
    @supply = supply
  end

  def calculate_deficit
    deficit = @demand - @supply
    [deficit, 0].max
  end

  def optimize_supply(additional_supply)
    @supply += additional_supply
  end
end

class SupplyChain
  def initialize(demand_sequence, supply_sequence)
    @demand_sequence = demand_sequence
    @supply_sequence = supply_sequence
    @optimizer = SupplyChainOptimizer.new(0, 0)
  end

  def run_optimization
    @demand_sequence.zip(@supply_sequence) do |demand, supply|
      @optimizer.supply = supply
      deficit = @optimizer.calculate_deficit
      if deficit > 0
        additional_supply = SequenceGenerator.new(deficit, 1).generate(1)[0]
        @optimizer.optimize_supply(additional_supply)
      end
      puts "Demand: #{demand}, Supply: #{supply}, Deficit: #{deficit}, Adjusted Supply: #{@optimizer.supply}"
    end
  end
end

def main
  demand_gen = SequenceGenerator.new(100, 10)
  demand_sequence = demand_gen.generate(10)
  supply_gen = SequenceGenerator.new(80, 5)
  supply_sequence = supply_gen.generate(10)
  supply_chain = SupplyChain.new(demand_sequence, supply_sequence)
  supply_chain.run_optimization
end

main