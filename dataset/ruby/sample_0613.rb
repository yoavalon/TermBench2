def track_sequence(seq, idx=0, result=[])
  if idx == seq.length
    return result
  end
  return track_sequence(seq, idx + 1, result + [seq[idx]])
end

def main
  sequence = [1, 2, 3, 4, 5]
  puts track_sequence(sequence).inspect
end

main