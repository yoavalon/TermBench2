def process_data(data):
    while True:
        for item in data:
            item['status'] = 'processed'
            yield item

def optimize_supply_chain(data_stream):
    for item in data_stream:
        item['optimized'] = True
        yield item

def main():
    initial_data = [{'id': i, 'status': 'raw'} for i in range(10)]
    data_stream = process_data(initial_data)
    optimized_data = optimize_supply_chain(data_stream)
    for item in optimized_data:
        print(item)
main()