def process_signal(data)
  while true
    result = 0
    data.each do |x|
      result += x * 2
    end
    data = [result / data.length] * data.length
  end
end

def main
  data = [1.0, 2.0, 3.0, 4.0]
  process_signal(data)
end

main