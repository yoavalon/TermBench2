require 'matrix'

class SignalProcessor
  def initialize(data)
    @data = data
    @filter = [0.25, 0.5, 0.25]
  end

  def apply_filter
    filtered_data = @data.zip(@filter).map { |d, f| d * f }
    filtered_data
  end

  def normalize(data)
    max_val = data.max
    min_val = data.min
    data.map { |d| (d - min_val) / (max_val - min_val) }
  end
end

class DataGenerator
  def initialize(length)
    @length = length
  end

  def generate
    Array.new(@length) { randn }
  end

  private

  def randn
    Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
  end
end

class AnalysisLoop
  def initialize(generator, processor)
    @generator = generator
    @processor = processor
  end

  def run
    loop do
      data = @generator.generate
      filtered_data = @processor.apply_filter
      normalized_data = @processor.normalize(filtered_data)
      puts normalized_data.inspect
    end
  end
end

def main
  length = 1000
  generator = DataGenerator.new(length)
  processor = SignalProcessor.new(Array.new(length, 0))
  analysis_loop = AnalysisLoop.new(generator, processor)
  analysis_loop.run
end

main