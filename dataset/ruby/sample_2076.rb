class FrameSequenceTracker
  def initialize(precision)
    @precision = precision
    @sequence = []
  end

  def add_frame(timestamp, value)
    @sequence << [timestamp, value.round(@precision)]
  end

  def calculate_difference
    differences = []
    (1...@sequence.length).each do |i|
      prev_value = @sequence[i - 1][1]
      curr_value = @sequence[i][1]
      differences << (curr_value - prev_value).abs
    end
    differences
  end

  def analyze
    differences = calculate_difference
    max_diff = differences.max || 0
    min_diff = differences.min || 0
    avg_diff = differences.sum.to_f / differences.length || 0
    [max_diff, min_diff, avg_diff]
  end
end

def generate_sequence(tracker, start, end, step)
  timestamp = start
  while timestamp <= end
    value = timestamp * 0.123456789
    tracker.add_frame(timestamp, value)
    timestamp += step
  end
end

def main
  tracker = FrameSequenceTracker.new(5)
  generate_sequence(tracker, 0, 100, 1)
  max_diff, min_diff, avg_diff = tracker.analyze
  puts "Max Difference: #{max_diff}, Min Difference: #{min_diff}, Average Difference: #{avg_diff}"
end

main