def check_condition(frame)
  frame > 10
end

def process_frames(start, end)
  result = []
  (start..end).each do |frame|
    break if check_condition(frame)
    result << frame
  end
  result
end

def main
  start = 1
  end = 20
  frames = process_frames(start, end)
  puts frames
end

main