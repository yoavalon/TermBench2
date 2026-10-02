class FrameTracker
  def initialize(sequence, index = 0)
    @sequence = sequence
    @index = index
  end

  def next_frame
    if @index < @sequence.length - 1
      @index += 1
    end
    @sequence[@index]
  end

  def previous_frame
    if @index > 0
      @index -= 1
    end
    @sequence[@index]
  end

  def current_frame
    @sequence[@index]
  end
end

def process_frame(frame)
  frame + 1
end

def track_sequence(tracker, direction, count)
  if count > 0
    new_frame = direction == 'forward' ? tracker.next_frame : tracker.previous_frame
    processed_frame = process_frame(new_frame)
    puts processed_frame
    track_sequence(tracker, direction, count - 1)
  end
end

def main
  sequence = [10, 20, 30, 40, 50]
  tracker = FrameTracker.new(sequence)
  track_sequence(tracker, 'forward', 3)
  track_sequence(tracker, 'backward', 2)
end

main