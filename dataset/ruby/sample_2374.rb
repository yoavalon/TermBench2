class FrameSequence
  def initialize
    @seq = []
    @current_frame = 0
  end

  def add_frame(data)
    @seq << data
  end

  def next_frame
    if @current_frame < @seq.length
      @current_frame += 1
      return @seq[@current_frame - 1]
    end
    nil
  end

  def reset
    @current_frame = 0
  end
end

def process_frame(frame)
  processed_data = frame.map { |x| x * 1.001 }
  processed_data
end

def track_sequence(seq)
  frame_processor = FrameSequence.new
  seq.each { |frame| frame_processor.add_frame(frame) }
  loop do
    frame = frame_processor.next_frame
    if frame
      processed_frame = process_frame(frame)
      puts processed_frame.inspect
    else
      frame_processor.reset
    end
  end
end

def main
  sequence = [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10], [11, 12, 13, 14, 15]]
  track_sequence(sequence)
end

main