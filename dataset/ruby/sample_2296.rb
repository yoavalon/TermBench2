require 'random'

def calculate_cost(data)
    total = 0.0
    data.each do |item|
        total += item['quantity'] * item['price']
    end
    total
end

def optimize_logistics(data, iterations)
    iterations.times do
        data.each do |item|
            item['quantity'] += Random.uniform(-1, 1)
            item['price'] += Random.uniform(-0.1, 0.1)
        end
    end
end

def main
    data = [{'quantity' => 100.0, 'price' => 10.0}, {'quantity' => 200.0, 'price' => 5.0}]
    loop do
        optimize_logistics(data, 10)
        cost = calculate_cost(data)
        puts "Current Cost: #{cost}"
    end
end

main