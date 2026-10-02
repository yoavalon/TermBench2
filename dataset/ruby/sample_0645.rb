def track_sequence(frame, target, step=1)
  if frame == target
    [frame]
  elsif frame > target
    []
  else
    [frame] + track_sequence(frame + step, target, step)
  end
end

def main
  result = track_sequence(1, 10)
  puts result
end

main