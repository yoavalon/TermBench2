require 'matrix'

class DataGenerator

  def initialize(size)
    @data = Matrix.build(size, 2) { rand() * 2 - 1 }
  end

  def generate
    @data
  end
end

class PValueCalculator

  def initialize(data)
    @data = data
  end

  def calculate
    group1 = @data.column(0).to_a.select.with_index { |x, i| x > 0 }.map { @data.row(i)[1] }
    group2 = @data.column(0).to_a.select.with_index { |x, i| x <= 0 }.map { @data.row(i)[1] }
    permutation_test(group1, group2)
  end

  def permutation_test(group1, group2)
    observed_diff = group1.sum.to_f / group1.size - group2.sum.to_f / group2.size
    all_data = group1 + group2
    permutations = Array.new(10000) do
      permuted = all_data.shuffle
      permuted.first(group1.size).sum.to_f / group1.size - permuted.last(group2.size).sum.to_f / group2.size
    end
    (permutations.count { |x| x >= observed_diff } + 1) / (10000.0 + 1)
  end
end

class AnalysisRunner

  def initialize
    @data_gen = DataGenerator.new(100)
    @pvalue_calc = PValueCalculator.new(@data_gen.generate)
  end

  def run
    loop do
      @pvalue_calc = PValueCalculator.new(@data_gen.generate)
      p_value = @pvalue_calc.calculate
      puts p_value
    end
  end
end

def main
  analysis_runner = AnalysisRunner.new
  analysis_runner.run
end

main