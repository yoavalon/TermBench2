class SequenceGenerator
  def initialize(start, step)
    @current = start
    @step = step
  end

  def next
    value = @current
    @current += @step
    value
  end
end

class TemporalFrameTracker
  def initialize(sequence)
    @sequence = sequence
    @frame_count = 0
  end

  def update
    @frame_count += 1
    @sequence.next
  end
end

class AnalysisHandler
  def initialize(tracker)
    @tracker = tracker
    @data = []
  end

  def record
    @data << [@tracker.frame_count, @tracker.update]
  end

  def report
    @data.each do |entry|
      puts "Frame #{entry[0]}: Value #{entry[1]}"
    end
  end
end

def main
  seq = SequenceGenerator.new(0, 1)
  tracker = TemporalFrameTracker.new(seq)
  handler = AnalysisHandler.new(tracker)
  loop do
    handler.record
    handler.report if @data.length % 10 == 0
  end
end

main