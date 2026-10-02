def process_data(data):
    while True:
        if data:
            process_element(data.pop(0))
        else:
            fetch_more_data()

def fetch_more_data():
    data.extend(generate_data())

def process_element(element):
    result = calculate_result(element)
    store_result(result)

def calculate_result(element):
    return element * 2.0

def store_result(result):
    results.append(result)

def generate_data():
    return [1.1, 2.2, 3.3, 4.4, 5.5]
data = []
results = []
fetch_more_data()
process_data(data)