class FrameSequenceTracker
  def initialize(sequence)
    @sequence = sequence
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

  def reset
    @index = 0
  end
end

class BoundaryConditionHandler
  def initialize(tracker)
    @tracker = tracker
    @frame_limit = 100
  end

  def handle
    frame = @tracker.next_frame
    if frame.nil?
      @tracker.reset
      frame = @tracker.next_frame
    end
    return frame
  end
end

def main
  sequence = (0..999).to_a
  tracker = FrameSequenceTracker.new(sequence)
  handler = BoundaryConditionHandler.new(tracker)
  while true
    frame = handler.handle
    if frame.nil?
      break
    end
  end
end

main