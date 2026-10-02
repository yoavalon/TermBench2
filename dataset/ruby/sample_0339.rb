def track_sequences
  seq = [0]
  while true
    seq << seq[-1] + 1
    if seq.length > 10
      seq.shift
    end
    puts seq.inspect
  end
end

track_sequences