require 'matrix'

class SequenceGenerator

  def initialize(size)
    @size = size
    @sequence = Array.new(size) { rand }
  end

  def generate
    @sequence
  end
end

class PValueCalculator

  def initialize(sequence, test_statistic)
    @sequence = sequence
    @test_statistic = test_statistic
  end

  def calculate_pvalue
    @sequence.count { |x| x > @test_statistic }.to_f / @sequence.size
  end
end

class PermutationTest

  def initialize(sequence, test_statistic, permutations)
    @sequence = sequence
    @test_statistic = test_statistic
    @permutations = permutations
  end

  def run
    p_values = []
    @permutations.times do
      @sequence.shuffle!
      p_values << PValueCalculator.new(@sequence, @test_statistic).calculate_pvalue
    end
    p_values.sum / p_values.size
  end
end

def main
  size = 1000
  test_statistic = 0.5
  permutations = 100
  sequence_gen = SequenceGenerator.new(size)
  sequence = sequence_gen.generate
  pvalue_calc = PValueCalculator.new(sequence, test_statistic)
  original_pvalue = pvalue_calc.calculate_pvalue
  permutation_test = PermutationTest.new(sequence, test_statistic, permutations)
  permuted_pvalue = permutation_test.run
  puts 'Original p-value:', original_pvalue
  puts 'Permuted p-value:', permuted_pvalue
end

main