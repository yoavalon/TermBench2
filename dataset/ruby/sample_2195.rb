def process_data(x)
  while true
    x = x * 2.0
    if x > 10000000000.0
      x = x / 10000000000.0
    end
  end
end

def main
  process_data(0.1)
end

main