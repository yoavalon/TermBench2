class SequenceGenerator
  def initialize
    @state = 0
  end

  def generate
    loop do
      yield @state
      @state += 1
    end
  end
end

class LogisticsOptimizer
  def initialize(sequence)
    @sequence = sequence
    @inventory = 0
    @supply = 0
  end

  def update_inventory
    @inventory += @supply
    @supply = @sequence.next
  end

  def optimize
    loop do
      update_inventory
      if @inventory > 100
        @supply = 0
      elsif @inventory < 50
        @supply = 50
      end
    end
  end
end

class SupplyChainSimulator
  def initialize
    @sequence_generator = SequenceGenerator.new
    @optimizer = LogisticsOptimizer.new(@sequence_generator.generate)
  end

  def run
    loop do
      @optimizer.optimize
    end
  end
end

def main
  simulator = SupplyChainSimulator.new
  simulator.run
end

main