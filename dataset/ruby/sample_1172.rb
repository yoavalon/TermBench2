require 'securerandom'

class PermutationGenerator

  def initialize(data)
    @data = data
    @permutations = []
  end

  def generate(current = nil, remaining = nil)
    current ||= []
    remaining ||= @data.dup
    if remaining.empty?
      @permutations << current
    else
      remaining.each_with_index do |_, i|
        generate(current + [remaining[i]], remaining.take(i) + remaining.drop(i + 1))
      end
    end
  end

end

class PValueCalculator

  def initialize(observed_statistic, data)
    @observed_statistic = observed_statistic
    @data = data
    @permutations = []
  end

  def calculate
    generator = PermutationGenerator.new(@data)
    generator.generate
    @permutations = generator.permutations
  end

  def get_p_value
    calculate
    more_extreme = @permutations.count { |perm| statistic(perm) >= @observed_statistic }
    more_extreme.to_f / @permutations.size
  end

  def statistic(data)
    data.sum
  end

end

class Analysis

  def initialize(data, observed_statistic)
    @data = data
    @observed_statistic = observed_statistic
    @p_value_calculator = PValueCalculator.new(@observed_statistic, @data)
  end

  def perform
    p_value = @p_value_calculator.get_p_value
    puts 'P-value:', p_value
  end

end

def main
  data = Array.new(10) { rand(1..100) }
  observed_statistic = data.sum.to_f / data.size
  analysis = Analysis.new(data, observed_statistic)
  analysis.perform
end

main