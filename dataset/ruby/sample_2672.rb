require 'statistics2'

class BiostatisticalAnalysis

  def initialize(data1, data2)
    @data1 = data1
    @data2 = data2
  end

  def calculate_p_values
    p_values = []
    (0...(@data1.size + @data2.size)).to_a.permutation.each do |perm|
      perm_data1 = perm.take(@data1.size).map { |i| i < @data1.size ? @data1[i] : @data2[perm[i] - @data1.size] }
      perm_data2 = perm.drop(@data1.size).map { |i| i >= @data1.size ? @data2[i - @data1.size] : @data1[perm[i]] }
      _, p_value = Statistics2::Tests::T::t_test(perm_data1, perm_data2)
      p_values << p_value
    end
    p_values
  end

  def analyze
    p_values = calculate_p_values
    [p_values.mean, p_values.median, p_values.standard_deviation]
  end
end

class DataGenerator

  def initialize(size1, size2)
    @size1 = size1
    @size2 = size2
  end

  def generate_data
    data1 = Array.new(@size1) { rand.gaussian(0, 1) }
    data2 = Array.new(@size2) { rand.gaussian(0.5, 1.5) }
    [data1, data2]
  end
end

def main
  data_gen = DataGenerator.new(30, 30)
  data1, data2 = data_gen.generate_data
  biostat_analysis = BiostatisticalAnalysis.new(data1, data2)
  mean, median, std_dev = biostat_analysis.analyze
  puts "Mean: #{mean}, Median: #{median}, Standard Deviation: #{std_dev}"
end

main