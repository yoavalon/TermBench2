def track_sequences
  seq = []
  loop do
    seq << seq.length
    puts seq.inspect
  end
end

track_sequences