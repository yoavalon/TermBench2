class FrameSequence
  def initialize(data)
    @data = data
    @index = 0
  end

  def update
    if @index < @data.length
      @data[@index] = @index + 1
      @index += 1
      return true
    end
    return false
  end

  def reset
    @index = 0
  end
end

class Tracker
  def initialize(sequence)
    @sequence = sequence
  end

  def monitor
    unless @sequence.update
      @sequence.reset
    end
  end
end

class Processor
  def initialize(tracker)
    @tracker = tracker
  end

  def process
    loop do
      @tracker.monitor
    end
  end
end

def main
  data = Array.new(10, 0)
  sequence = FrameSequence.new(data)
  tracker = Tracker.new(sequence)
  processor = Processor.new(tracker)
  processor.process
end

main