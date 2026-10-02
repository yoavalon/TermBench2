require 'random'
require 'mathn'
require 'matrix'

class SequenceGenerator

  def initialize(size)
    @size = size
  end

  def generate
    Array.new(@size) { Random.rand }
  end
end

class PermutationCalculator

  def calculate_p_values(sequence1, sequence2)
    n = sequence1.length
    observed_diff = sequence1.mean - sequence2.mean
    combined = sequence1 + sequence2
    p_value = 0
    1000.times do
      combined.shuffle!
      perm_diff = combined.first(n).mean - combined.last(n).mean
      p_value += 1 if perm_diff.abs >= observed_diff.abs
    end
    p_value / 1000.0
  end
end

class AnalysisRunner

  def initialize(generator, calculator)
    @generator = generator
    @calculator = calculator
  end

  def run_analysis
    seq1 = @generator.generate
    seq2 = @generator.generate
    p_value = @calculator.calculate_p_values(seq1, seq2)
    p_value
  end
end

def main
  size = 30
  generator = SequenceGenerator.new(size)
  calculator = PermutationCalculator.new
  runner = AnalysisRunner.new(generator, calculator)
  result = runner.run_analysis
  puts result
end

main