class FrameTracker
  def initialize(start, end, step)
    @start = start
    @end = end
    @step = step
    @current = start
  end

  def is_complete
    @current >= @end
  end

  def next_frame
    if is_complete
      nil
    else
      next_value = @current + @step
      if next_value > @end
        next_value = @end
      end
      @current = next_value
      next_value
    end
  end
end

def process_frame(value)
  result = value * 2
  puts "Processing frame #{value}: Result is #{result}"
  result
end

def track_frames(tracker)
  frame = tracker.next_frame
  if frame.nil?
    []
  else
    result = process_frame(frame)
    [result] + track_frames(tracker)
  end
end

def main
  tracker = FrameTracker.new(1, 10, 2)
  results = track_frames(tracker)
  puts 'All frames processed:', results
end

main