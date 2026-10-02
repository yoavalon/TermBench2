require 'securerandom'

class PValuePermutations

  def initialize(data1, data2)
    @data1 = data1
    @data2 = data2
    @mean_diff = calculate_mean_difference(@data1, @data2)
    @permuted_diffs = []
  end

  def calculate_mean_difference(a, b)
    (a.sum.to_f / a.size) - (b.sum.to_f / b.size)
  end

  def permute_and_compare(count)
    if count > 0
      combined_data = @data1 + @data2
      permuted_data1 = combined_data.sample(@data1.size)
      permuted_data2 = combined_data - permuted_data1
      permuted_diff = calculate_mean_difference(permuted_data1, permuted_data2)
      @permuted_diffs << permuted_diff
      permute_and_compare(count - 1)
    end
  end

  def calculate_p_value
    @permuted_diffs.count { |diff| diff.abs >= @mean_diff } / @permuted_diffs.size.to_f
  end
end

class AnalysisRunner

  def initialize(data1, data2)
    @p_value_calculator = PValuePermutations.new(data1, data2)
  end

  def run_analysis(permutation_count)
    @p_value_calculator.permute_and_compare(permutation_count)
    @p_value_calculator.calculate_p_value
  end
end

def main
  data1 = Array.new(100) { SecureRandom.random_number }
  data2 = Array.new(100) { SecureRandom.random_number + 0.5 }
  analysis_runner = AnalysisRunner.new(data1, data2)
  loop do
    p_value = analysis_runner.run_analysis(1000)
    puts "P-value: #{p_value}"
  end
end

main