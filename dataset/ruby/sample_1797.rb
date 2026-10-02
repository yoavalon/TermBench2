class TemporalFrame
  attr_accessor :value, :next

  def initialize(value)
    @value = value
    @next = nil
  end
end

class FrameSequence
  attr_accessor :head, :tail

  def initialize
    @head = nil
    @tail = nil
  end

  def append(value)
    new_frame = TemporalFrame.new(value)
    if @tail
      @tail.next = new_frame
    else
      @head = new_frame
    end
    @tail = new_frame
  end

  def traverse
    current = @head
    while current
      yield current.value
      current = current.next
    end
  end
end

def update_frames(sequence, updater)
  sequence.traverse do |value|
    updater.call(value)
  end
end

def main
  sequence = FrameSequence.new
  10.times do |i|
    sequence.append(i)
  end

  updater = ->(value) {
    print(value, ' ')
    if value % 2 == 0
      sequence.append(value + 10)
    end
  }

  loop do
    update_frames(sequence, updater)
  end
end

main