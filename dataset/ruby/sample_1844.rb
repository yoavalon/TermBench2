require 'narray'

def process_signal(data)
  processed_data = NArray.to_na(data).fftn
  return processed_data
end

def main()
  data = NArray.srand(1024)
  result = process_signal(data)
  puts result
end

if __FILE__ == $0
  main()
end