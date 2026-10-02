def track_sequence(sequence, threshold)
  state = 0
  sequence.each do |frame|
    if frame > threshold
      state += 1
    else
      state = 0
    end
    return true if state >= 3
  end
  false
end

def analyze_data(data, limit)
  data.each do |item|
    return true if track_sequence(item, limit)
  end
  false
end

def main
  data = [[1, 2, 3, 4], [4, 5, 6, 7], [7, 8, 9, 10]]
  limit = 6
  result = analyze_data(data, limit)
  puts result
end

main