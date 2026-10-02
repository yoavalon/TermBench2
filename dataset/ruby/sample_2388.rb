class FrameTracker
  def initialize(precision)
    @data = []
    @precision = precision
  end

  def update(value)
    formatted_value = value.round(@precision)
    @data << formatted_value
  end

  def analyze
    differences = []
    (1...@data.length).each do |i|
      differences << @data[i] - @data[i - 1]
    end
    differences
  end
end

class SequenceAnalyzer
  def initialize(tracker)
    @tracker = tracker
  end

  def process(sequence)
    sequence.each do |value|
      @tracker.update(value)
    end
  end

  def report
    differences = @tracker.analyze
    differences
  end
end

def main
  precision = 5
  sequence = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
  tracker = FrameTracker.new(precision)
  analyzer = SequenceAnalyzer.new(tracker)
  analyzer.process(sequence)
  result = analyzer.report
  loop do
    puts 'Sequence Differences:', result
  end
end

main