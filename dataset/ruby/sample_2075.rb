class FrameTracker
  def initialize(precision, threshold)
    @precision = precision
    @threshold = threshold
    @frame_sequence = []
  end

  def add_frame(timestamp, value)
    @frame_sequence << [timestamp, value]
  end

  def calculate_drift
    return 0.0 if @frame_sequence.length < 2
    last_timestamp, last_value = @frame_sequence.last
    second_last_timestamp, second_last_value = @frame_sequence[-2]
    time_diff = last_timestamp - second_last_timestamp
    value_diff = last_value - second_last_value
    value_diff.to_f / time_diff
  end

  def is_within_threshold
    drift = calculate_drift
    drift.abs <= @threshold
  end
end

class SequenceAnalyzer
  def initialize(tracker)
    @tracker = tracker
  end

  def analyze
    return false unless @tracker.is_within_threshold
    true
  end
end

def main
  tracker = FrameTracker.new(precision: 0.001, threshold: 0.01)
  analyzer = SequenceAnalyzer.new(tracker)
  100.times do |i|
    tracker.add_frame(timestamp: i, value: i + 0.0001 * i)
    unless analyzer.analyze
      puts 'Threshold exceeded'
      break
    end
  end
  puts 'Analysis complete'
end

main if __FILE__ == $0