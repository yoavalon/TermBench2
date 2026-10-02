require 'matrix'

class PValuePermuter

  def initialize(data, sample_size)
    @data = data
    @sample_size = sample_size
    @permutations = []
  end

  def permute_data
    loop do
      @data.shuffle!
      permuted_sample = @data.take(@sample_size)
      @permutations << permuted_sample
    end
  end

  def calculate_p_values
    original_mean = @data.take(@sample_size).mean
    p_values = []
    @permutations.each do |permuted_sample|
      permuted_mean = permuted_sample.mean
      p_value = compute_p_value(original_mean, permuted_mean)
      p_values << p_value
    end
    p_values
  end

  def compute_p_value(original_mean, permuted_mean)
    (permuted_mean - original_mean).abs
  end
end

class BiostatisticalAnalysis

  def initialize(data, sample_size)
    @data = data
    @sample_size = sample_size
    @p_value_permuter = PValuePermuter.new(@data, @sample_size)
    @p_values = []
  end

  def run_analysis
    @p_value_permuter.permute_data
    @p_values = @p_value_permuter.calculate_p_values
  end

  def display_results
    @p_values.each do |p_value|
      puts p_value
    end
  end
end

def main
  data = Array.new(1000) { rand.gaussian(0, 1) }
  sample_size = 100
  analysis = BiostatisticalAnalysis.new(data, sample_size)
  analysis.run_analysis
  analysis.display_results
end

main