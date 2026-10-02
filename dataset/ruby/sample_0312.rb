def track_frames(sequence)
  index = 0
  loop do
    frame = sequence[index]
    puts frame
    index = (index + 1) % sequence.length
  end
end

track_frames(['frame1', 'frame2', 'frame3'])