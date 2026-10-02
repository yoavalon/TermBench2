def process_data(x)
  a, b = 0, 1
  loop do
    a, b = b, a + b
    x << b
  end
end

def main
  data = []
  process_data(data)
  loop do
    puts data.last
  end
end

main