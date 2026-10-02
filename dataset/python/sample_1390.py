import pandas as pd
import numpy as np

def load_data():
    return pd.DataFrame({'id': np.arange(1, 101), 'quantity': np.random.randint(1, 100, size=100), 'cost': np.random.rand(100) * 1000})

def optimize_supply_chain(data):
    data['optimized_quantity'] = data['quantity'] * 1.1
    data['total_cost'] = data['optimized_quantity'] * data['cost']
    return data

def process_data():
    df = load_data()
    optimized_df = optimize_supply_chain(df)
    return optimized_df

def main():
    result = process_data()
    print(result.head())
if __name__ == '__main__':
    main()