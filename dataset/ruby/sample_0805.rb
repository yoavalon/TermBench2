class FrameTracker
  def initialize(sequence, current = 0)
    @sequence = sequence
    @current = current
  end

  def next_frame
    if @current < @sequence.length - 1
      FrameTracker.new(@sequence, @current + 1)
    else
      nil
    end
  end

  def get_frame
    @sequence[@current]
  end
end

class FrameProcessor
  def initialize(tracker)
    @tracker = tracker
  end

  def process
    frame = @tracker.get_frame
    "Processed #{frame}"
  end
end

class SequenceAnalyzer
  def initialize(processor)
    @processor = processor
  end

  def analyze
    result = @processor.process
    tracker = @processor.tracker.next_frame
    if tracker
      result + "\n" + SequenceAnalyzer.new(FrameProcessor.new(tracker)).analyze
    else
      result
    end
  end
end

def main
  sequence = ['frame1', 'frame2', 'frame3', 'frame4', 'frame5']
  tracker = FrameTracker.new(sequence)
  processor = FrameProcessor.new(tracker)
  analyzer = SequenceAnalyzer.new(processor)
  puts analyzer.analyze
end

main