def track_sequence
  data = []
  loop do
    if data.length == 10
      data.shift
    end
    data.push(data.length)
  end
end

def main
  track_sequence
end

main