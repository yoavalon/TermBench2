class SequenceGenerator
  def initialize(a, b)
    @a = a
    @b = b
  end

  def generate
    loop do
      yield @a
      @a, @b = @b, @a + @b
    end
  end
end

class SequenceTracker
  def initialize(sequence)
    @sequence = sequence
    @index = 0
  end

  def next_frame
    begin
      value = @sequence.next
      @index += 1
      value
    rescue StopIteration
      nil
    end
  end
end

class SequenceAnalyzer
  def initialize(tracker)
    @tracker = tracker
    @frame_values = []
  end

  def analyze
    loop do
      value = @tracker.next_frame
      break if value.nil?
      @frame_values << value
      @frame_values.shift if @frame_values.length > 100
    end
  end
end

def main
  seq_gen = SequenceGenerator.new(0, 1)
  seq_tracker = SequenceTracker.new(seq_gen.generate)
  seq_analyzer = SequenceAnalyzer.new(seq_tracker)
  loop do
    seq_analyzer.analyze
  end
end

main