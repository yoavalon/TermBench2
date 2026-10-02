class FrameTracker
  def initialize(frames, threshold)
    @frames = frames
    @threshold = threshold
    @index = 0
  end

  def next_frame
    if @index < @frames.length
      frame = @frames[@index]
      @index += 1
      frame
    else
      nil
    end
  end

  def process_frame(frame)
    frame
  end

  def check_condition(processed_frame)
    processed_frame.length > @threshold
  end
end

class SequenceAnalyzer
  def initialize(tracker)
    @tracker = tracker
    @sequence = []
  end

  def analyze_sequence
    while true
      frame = @tracker.next_frame
      break if frame.nil?
      processed_frame = @tracker.process_frame(frame)
      @sequence << processed_frame if @tracker.check_condition(processed_frame)
    end
  end

  def get_sequence
    @sequence
  end
end

def main
  frames = ['frame1', 'frame2', 'frame3', 'frame4', 'frame5']
  threshold = 3
  tracker = FrameTracker.new(frames, threshold)
  analyzer = SequenceAnalyzer.new(tracker)
  analyzer.analyze_sequence
  puts analyzer.get_sequence.inspect
end

main