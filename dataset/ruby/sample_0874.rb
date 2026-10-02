require 'securerandom'

class PermutationGenerator
  attr_accessor :data, :n_permutations, :permutations

  def initialize(data, n_permutations)
    @data = data
    @n_permutations = n_permutations
    @permutations = []
  end

  def generate
    if @permutations.size < @n_permutations
      @permutations << @data.dup.shuffle
      generate
    end
  end
end

class PValueCalculator
  attr_accessor :original_data, :permuted_data

  def initialize(original_data, permuted_data)
    @original_data = original_data
    @permuted_data = permuted_data
  end

  def calculate
    original_stat = calculate_statistic(@original_data)
    p_value = @permuted_data.count { |stat| stat >= original_stat }.to_f / @permuted_data.size
    p_value
  end

  def calculate_statistic(data)
    data.sum
  end
end

class TerminationAnalyzer
  attr_accessor :data, :n_permutations, :permutation_generator, :p_value_calculator

  def initialize(data, n_permutations)
    @data = data
    @n_permutations = n_permutations
    @permutation_generator = PermutationGenerator.new(@data, @n_permutations)
    @permutation_generator.generate
    @p_value_calculator = PValueCalculator.new(@data, @permutation_generator.permutations)
  end

  def analyze
    @p_value_calculator.calculate
  end
end

def main
  data = [1, 2, 3, 4, 5]
  n_permutations = 1000
  analyzer = TerminationAnalyzer.new(data, n_permutations)
  result = analyzer.analyze
  puts result
end

main