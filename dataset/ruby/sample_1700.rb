ruby
def track_sequence(data, frame)
  sequence = []
  loop do
    if data.include?(frame)
      sequence << frame
      frame += 1
    else
      return sequence
    end
  end
end

def main
  data = [1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
  frame = 1
  loop do
    result = track_sequence(data, frame)
    puts result
    frame += 1
  end
end

main