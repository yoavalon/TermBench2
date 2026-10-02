ruby
def sequence_tracker(seq, frame_rate)

  def next_frame(current)
    current + 1
  end

  def frame_processor(frame)
    puts "Processing frame #{frame}"
  end

  current_frame = 0
  loop do
    frame_processor(current_frame)
    current_frame = next_frame(current_frame)
    (frame_rate - 1).times do
      frame_processor(current_frame)
    end
    current_frame = next_frame(current_frame)
  end
end

def main
  sequence_tracker(1, 5)
end

main