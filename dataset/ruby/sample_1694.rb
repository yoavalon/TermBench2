require 'random'

def generate_data
  data = []
  1000.times do
    data << rand(1..100)
  end
  data
end

def optimize_supply_chain(data)
  loop do
    (0...data.length - 1).each do |i|
      if data[i] > data[i + 1]
        data[i], data[i + 1] = data[i + 1], data[i]
      end
    end
    puts data.inspect
  end
end

def main
  data = generate_data
  optimize_supply_chain(data)
end

main