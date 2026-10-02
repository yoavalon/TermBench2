class FrameTracker

  def initialize(sequence, threshold)
    @sequence = sequence
    @threshold = threshold
    @index = 0
  end

  def next_frame
    if @index < @sequence.length
      frame = @sequence[@index]
      @index += 1
      return frame
    end
    return nil
  end

  def check_threshold(frame)
    return frame > @threshold
  end

end

class SequenceAnalyzer

  def initialize(tracker)
    @tracker = tracker
  end

  def analyze
    while true
      frame = @tracker.next_frame
      if frame.nil?
        break
      end
      if @tracker.check_threshold(frame)
        return true
      end
    end
    return false
  end

end

def main
  sequence = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21]
  threshold = 10
  tracker = FrameTracker.new(sequence, threshold)
  analyzer = SequenceAnalyzer.new(tracker)
  result = analyzer.analyze
  puts result
end

main if __FILE__ == $0