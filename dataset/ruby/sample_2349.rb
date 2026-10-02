class FrameTracker
  def initialize(seq)
    @seq = seq
    @index = 0
    @precision = 1e-09
  end

  def update
    if @index < @seq.length
      current_frame = @seq[@index]
      next_frame = @index + 1 < @seq.length ? @seq[@index + 1] : current_frame
      @index += 1
      return [current_frame, next_frame]
    end
    return nil
  end

  def analyze(frame_pair)
    if frame_pair
      current, next_frame = frame_pair
      difference = (next_frame - current).abs
      if difference < @precision
        return 'Stable'
      else
        return 'Changing'
      end
    end
    return 'No Change'
  end
end

def track_frames(sequence)
  tracker = FrameTracker.new(sequence)
  loop do
    frame_pair = tracker.update
    status = tracker.analyze(frame_pair)
    puts status
  end
end

def main
  sequence = [0.0001, 0.00015, 0.0002, 0.00025, 0.0003]
  track_frames(sequence)
end

main