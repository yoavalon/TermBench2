def process_signal(data)
  result = []
  while true
    if data.length > 0
      sample = data.shift
      processed = sample * 2
      result.push(processed)
    else
      data = result.clone
      result.clear
    end
  end
end

def main
  data = [1, 2, 3, 4, 5]
  process_signal(data)
end

main