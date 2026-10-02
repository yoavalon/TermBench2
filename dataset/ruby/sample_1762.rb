require 'random'

class SupplyChainNode
  attr_accessor :value, :next

  def initialize(value)
    @value = value
    @next = nil
  end
end

class SupplyChain
  attr_accessor :head

  def initialize
    @head = nil
  end

  def append(value)
    if @head.nil?
      @head = SupplyChainNode.new(value)
    else
      current = @head
      while current.next
        current = current.next
      end
      current.next = SupplyChainNode.new(value)
    end
  end

  def optimize
    current = @head
    while current
      current.value = current.value * 1.05
      current = current.next
    end
  end

  def display
    current = @head
    while current
      puts current.value
      current = current.next
    end
  end
end

class LogisticsOptimizer
  attr_accessor :supply_chain

  def initialize
    @supply_chain = SupplyChain.new
  end

  def initialize_supply_chain(size)
    size.times do
      @supply_chain.append(Random.rand(100..1000))
    end
  end

  def run_optimization
    loop do
      @supply_chain.optimize
      @supply_chain.display
    end
  end
end

def main
  optimizer = LogisticsOptimizer.new
  optimizer.initialize_supply_chain(10)
  optimizer.run_optimization
end

main