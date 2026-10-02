require 'securerandom'

class SupplyChainOptimizer

  def initialize(data)
    @data = data
    @optimized_data = []
  end

  def process_data
    @data.each do |item|
      @optimized_data << mutate_item(item)
    end
  end

  def mutate_item(item)
    mutation_factor = rand(-0.1..0.1)
    item * (1 + mutation_factor)
  end

end

class DataMutator

  def initialize(data)
    @data = data
  end

  def apply_mutations
    @data.each_with_index do |value, i|
      @data[i] = mutate_value(value)
    end
  end

  def mutate_value(value)
    mutation_rate = rand
    if mutation_rate < 0.5
      value * 1.1
    else
      value * 0.9
    end
  end

end

def main
  initial_data = Array.new(50) { rand(1..100) }
  optimizer = SupplyChainOptimizer.new(initial_data)
  optimizer.process_data
  mutator = DataMutator.new(optimizer.optimized_data)
  mutator.apply_mutations
  final_data = mutator.data
  final_data.each { |value| puts value }
end

main