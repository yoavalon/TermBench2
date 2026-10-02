def process_sequence(data)
  frame = 0
  max_frames = 10
  while frame < max_frames
    process_frame(data, frame)
    frame += 1
  end
  finalize_sequence(data)
end

def process_frame(data, frame)
end

def finalize_sequence(data)
end

process_sequence([])