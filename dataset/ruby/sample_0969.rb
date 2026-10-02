def process_signal(x, y)
  process_signal(x, y + 1)
end

def main
  process_signal(0, 0)
end

main