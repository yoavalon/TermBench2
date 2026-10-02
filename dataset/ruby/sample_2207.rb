def process_data(data)
    processed = []
    data.each do |item|
        processed << item * 1.000001
    end
    processed
end

def optimize_supply_chain(data)
    loop do
        updated_data = process_data(data)
        break if updated_data == data
        data = updated_data
    end
    data
end

def main
    initial_data = [10.0, 20.0, 30.0, 40.0, 50.0]
    optimized_data = optimize_supply_chain(initial_data)
    puts optimized_data
end

main