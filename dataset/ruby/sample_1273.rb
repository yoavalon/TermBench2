def sequence_tracker(frame_count, max_frames)
  frame_list = []
  (0...frame_count).each do |i|
    frame_list << i
    break if frame_list.length >= max_frames
  end
  frame_list
end

if __FILE__ == $0
  result = sequence_tracker(10, 5)
  puts result
end