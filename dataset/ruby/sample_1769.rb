class FrameSequence
  def initialize
    @frames = []
    @current_index = 0
  end

  def add_frame(data)
    @frames << data
  end

  def get_current_frame
    @frames[@current_index]
  end

  def advance_frame
    @current_index += 1 if @current_index < @frames.length - 1
  end
end

class FrameProcessor
  def initialize(sequence)
    @sequence = sequence
  end

  def process
    loop do
      frame = @sequence.get_current_frame
      processed_data = modify_frame(frame)
      puts processed_data
      @sequence.advance_frame
    end
  end

  def modify_frame(frame)
    frame.upcase
  end
end

class DataHandler
  def initialize
    @frame_sequence = FrameSequence.new
    @frame_processor = FrameProcessor.new(@frame_sequence)
  end

  def load_data
    @frame_sequence.add_frame('frame1')
    @frame_sequence.add_frame('frame2')
    @frame_sequence.add_frame('frame3')
  end

  def start_processing
    @frame_processor.process
  end
end

def main
  handler = DataHandler.new
  handler.load_data
  handler.start_processing
end

main