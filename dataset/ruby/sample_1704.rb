class TemporalFrame
  def initialize(data)
    @data = data
    @timestamp = 0
  end

  def update(new_data)
    @data = new_data
    @timestamp += 1
  end

  def get_data
    [@data, @timestamp]
  end
end

class FrameSequence
  def initialize
    @frames = []
    @current_index = 0
  end

  def add_frame(frame)
    @frames << frame
  end

  def next_frame
    if @current_index < @frames.length
      frame = @frames[@current_index]
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

class FrameProcessor
  def initialize(sequence)
    @sequence = sequence
  end

  def process_frames
    loop do
      frame = @sequence.next_frame
      if frame
        data, timestamp = frame.get_data
        puts "Processing frame #{timestamp}: #{data}"
      else
        @sequence.reset
      end
    end
  end
end

def main
  frame1 = TemporalFrame.new('Data 1')
  frame2 = TemporalFrame.new('Data 2')
  frame3 = TemporalFrame.new('Data 3')
  sequence = FrameSequence.new
  sequence.add_frame(frame1)
  sequence.add_frame(frame2)
  sequence.add_frame(frame3)
  processor = FrameProcessor.new(sequence)
  processor.process_frames
end

main