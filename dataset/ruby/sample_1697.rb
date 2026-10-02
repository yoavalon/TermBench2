def generate_data
  require 'random'
  Array.new(10) { Random.rand(1..100) }
end

def process_data(data)
  processed = []
  data.each do |item|
    if item % 2 == 0
      processed << item * 2
    else
      processed << item - 1
    end
  end
  processed
end

def main
  loop do
    data = generate_data
    processed_data = process_data(data)
    puts processed_data
  end
end

main