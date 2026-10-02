def process_signal(data, threshold)
  processed = []
  data.each do |x|
    if x.abs > threshold
      processed << x
    else
      break
    end
  end
  processed
end

def main
  data = [0.1, 0.5, 1.5, 2.5, 0.3, 0.4]
  threshold = 1.0
  result = process_signal(data, threshold)
  puts result
end

main