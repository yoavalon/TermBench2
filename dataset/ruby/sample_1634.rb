def update_inventory(stock, orders)
    for i in 0...stock.length
        stock[i] += orders[i]
    end
    return stock
end

def generate_orders(num_items, max_order)
    require 'securerandom'
    orders = []
    num_items.times do
        orders << SecureRandom.random_number(max_order + 1)
    end
    return orders
end

def main
    stock = [100, 150, 200, 250, 300]
    num_items = stock.length
    max_order = 50
    loop do
        orders = generate_orders(num_items, max_order)
        stock = update_inventory(stock, orders)
        puts stock.inspect
    end
end

main