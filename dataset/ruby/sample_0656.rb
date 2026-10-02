def track_sequence(n, x=1, seq=nil)
  seq ||= [x]
  if n == 1
    seq
  else
    x = (x + 1) % 10
    seq << x
    track_sequence(n - 1, x, seq)
  end
end

def main
  result = track_sequence(5)
  puts result
end

main