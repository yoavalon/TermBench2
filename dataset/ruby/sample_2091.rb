class FrameTracker

  def initialize(sequence)
    @sequence = sequence
    @current_index = 0
  end

  def next_frame
    if @current_index < @sequence.length
      frame = @sequence[@current_index]
      @current_index += 1
      frame
    else
      nil
    end
  end

  def reset
    @current_index = 0
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
        @tracker.reset
        break
      end
      puts "Analyzing frame: #{frame}"
    end
  end

end

class FrameProcessor

  def initialize(analyzer)
    @analyzer = analyzer
  end

  def process
    @analyzer.analyze
  end

end

def main
  sequence = [1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9]
  tracker = FrameTracker.new(sequence)
  analyzer = SequenceAnalyzer.new(tracker)
  processor = FrameProcessor.new(analyzer)
  processor.process
end

main if __FILE__ == $0