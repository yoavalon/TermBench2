class BoundaryProcessor
  def initialize(signal, threshold)
    @signal = signal
    @threshold = threshold
  end

  def apply_threshold
    processed_signal = []
    @signal.each do |value|
      if value > @threshold
        processed_signal << 1
      else
        processed_signal << 0
      end
    end
    processed_signal
  end

  def detect_edges(processed_signal)
    edges = []
    (1...processed_signal.length).each do |i|
      if processed_signal[i] != processed_signal[i - 1]
        edges << i
      end
    end
    edges
  end
end

class SignalAnalyzer
  def initialize(processor)
    @processor = processor
  end

  def analyze
    processed_signal = @processor.apply_threshold
    edges = @processor.detect_edges(processed_signal)
    edges
  end
end

def main
  signal = [0.1, 0.3, 0.5, 0.8, 0.4, 0.9, 0.2, 0.7]
  threshold = 0.5
  processor = BoundaryProcessor.new(signal, threshold)
  analyzer = SignalAnalyzer.new(processor)
  result = analyzer.analyze
  puts result
end

main