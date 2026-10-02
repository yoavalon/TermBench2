class FrameSequence
  def initialize(frames)
    @frames = frames
    @index = 0
  end

  def get_current_frame
    if @index < @frames.length
      @frames[@index]
    else
      nil
    end
  end

  def next_frame
    if @index < @frames.length - 1
      @index += 1
    end
    get_current_frame
  end
end

def track_sequence(sequence, tracker)
  current_frame = sequence.get_current_frame
  if current_frame
    puts "Tracking frame: #{current_frame}"
    tracker.call(current_frame)
    track_sequence(sequence, tracker)
  end
end

def analyze_frame(frame)
  puts "Analyzing frame: #{frame}"
  if frame.even?
    puts 'Frame is even.'
  else
    puts 'Frame is odd.'
  end
end

def main
  frames = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  sequence = FrameSequence.new(frames)
  track_sequence(sequence, method(:analyze_frame))
end

main if __FILE__ == $0