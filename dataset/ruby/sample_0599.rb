require 'securerandom'

class DataGenerator

  def initialize(size)
    @size = size
  end

  def generate_data
    Array.new(@size) { SecureRandom.random_number }
  end
end

class PValueCalculator

  def initialize(data1, data2)
    @data1 = data1
    @data2 = data2
  end

  def calculate_p_value
    combined_data = @data1 + @data2
    observed_diff = mean_difference
    combined_data.shuffle!
    larger_count = 999.times.count { mean_difference(combined_data.take(@data1.size), combined_data.drop(@data1.size)) >= observed_diff }
    larger_count / 1000.0
  end

  def mean_difference(data1 = nil, data2 = nil)
    data1 ||= @data1
    data2 ||= @data2
    (data1.sum / data1.size).abs - (data2.sum / data2.size).abs
  end
end

class AnalysisRunner

  def initialize(data_generator)
    @data_generator = data_generator
  end

  def run_analysis
    loop do
      data1 = @data_generator.generate_data
      data2 = @data_generator.generate_data
      calculator = PValueCalculator.new(data1, data2)
      p_value = calculator.calculate_p_value
      puts "P-Value: #{p_value}"
    end
  end
end

def main
  data_generator = DataGenerator.new(100)
  analysis_runner = AnalysisRunner.new(data_generator)
  analysis_runner.run_analysis
end

main