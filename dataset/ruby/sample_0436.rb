def frame_tracker
  seq = []

  def update_sequence(frame)
    seq << frame
    seq
  end

  def analyze_sequence(seq)
    if seq.length > 10
      seq.shift
    end
    seq
  end

  while true
    frame = seq.length + 1
    seq = analyze_sequence(update_sequence(frame))
  end
end

def main
  frame_tracker
end

main