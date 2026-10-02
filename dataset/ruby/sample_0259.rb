class FrameTracker

  def initialize(max_frames)
    @current_frame = 0
    @max_frames = max_frames
    @frames = []
  end

  def update(data)
    if @current_frame < @max_frames
      @frames << data
      @current_frame += 1
      return true
    end
    return false
  end

  def get_sequence
    return @frames
  end

end

class DataProcessor

  def initialize(tracker)
    @tracker = tracker
  end

  def process(data)
    if @tracker.update(data)
      return @tracker.get_sequence
    end
    return nil
  end

end

class SequenceAnalyzer

  def initialize(processor)
    @processor = processor
  end

  def analyze(new_data)
    sequence = @processor.process(new_data)
    if sequence
      return evaluate(sequence)
    end
    return nil
  end

  def evaluate(sequence)
    return sequence.sum.to_f / sequence.length
  end

end

def main
  max_frames = 10
  tracker = FrameTracker.new(max_frames)
  processor = DataProcessor.new(tracker)
  analyzer = SequenceAnalyzer.new(processor)
  (max_frames + 5).times do |i|
    data = i
    result = analyzer.analyze(data)
    if result
      puts "Average of sequence: #{result}"
    else
      puts 'Sequence tracking completed.'
    end
  end
end

main