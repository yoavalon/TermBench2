class FrameSequence
  def initialize(initial_frame)
    @frame = initial_frame
    @history = []
  end

  def update(new_frame)
    @history << @frame
    @frame = new_frame
  end

  def get_history
    @history
  end
end

class Tracker
  def initialize(sequence)
    @sequence = sequence
  end

  def observe(current_frame)
    @sequence.update(current_frame)
  end

  def retrieve_history
    @sequence.get_history
  end
end

class Processor
  def initialize(tracker)
    @tracker = tracker
    @frame = 0
  end

  def process
    loop do
      @frame += 1
      @tracker.observe(@frame)
    end
  end
end

def main
  initial_frame = 0
  sequence = FrameSequence.new(initial_frame)
  tracker = Tracker.new(sequence)
  processor = Processor.new(tracker)
  processor.process
end

main