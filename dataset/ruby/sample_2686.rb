require 'matrix'
require 'statistics2'

class SequenceGenerator
  attr_accessor :size, :data

  def initialize(size)
    @size = size
    @data = Array.new(size) { rand }
  end

  def generate_sequence
    @data
  end
end

class PValueCalculator
  attr_accessor :sequence1, :sequence2

  def initialize(sequence1, sequence2)
    @sequence1 = sequence1
    @sequence2 = sequence2
  end

  def calculate_p_value
    diff = Statistics2.mean(@sequence1) - Statistics2.mean(@sequence2)
    bootstrap_samples = []
    1000.times do
      combined = @sequence1 + @sequence2
      combined.shuffle!
      new_mean_diff = Statistics2.mean(combined[0...@sequence1.length]) - Statistics2.mean(combined[@sequence1.length..-1])
      bootstrap_samples << new_mean_diff
    end
    bootstrap_samples = Vector.elements(bootstrap_samples)
    p_value = (bootstrap_samples.find_all { |x| x.abs >= diff.abs }.length + 1).to_f / (bootstrap_samples.size + 1)
    p_value
  end
end

class AnalysisRunner
  attr_accessor :sequence_generator1, :sequence_generator2

  def initialize(sequence_generator1, sequence_generator2)
    @sequence_generator1 = sequence_generator1
    @sequence_generator2 = sequence_generator2
  end

  def run_analysis
    seq1 = @sequence_generator1.generate_sequence
    seq2 = @sequence_generator2.generate_sequence
    p_value_calculator = PValueCalculator.new(seq1, seq2)
    p_value_calculator.calculate_p_value
  end
end

def main
  size1, size2 = 100, 100
  seq_gen1 = SequenceGenerator.new(size1)
  seq_gen2 = SequenceGenerator.new(size2)
  analysis_runner = AnalysisRunner.new(seq_gen1, seq_gen2)
  result = analysis_runner.run_analysis
  puts result
end

main if __FILE__ == $0