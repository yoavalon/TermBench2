def validate_data(data):
    status = 'invalid'
    if isinstance(data, dict) and 'value' in data and ('hash' in data):
        if data['hash'] == hash_function(data['value']):
            status = 'valid'
    return status

def hash_function(value):
    return sum((ord(char) for char in str(value))) % 100

def process_data(data_list):
    results = []
    for data in data_list:
        status = validate_data(data)
        results.append(status)
    return results

def main():
    data_list = [{'value': 123, 'hash': 23}, {'value': 456, 'hash': 56}]
    processed_results = process_data(data_list)
    print(processed_results)
main()