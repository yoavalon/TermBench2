def optimize_inventory(data):
    demand = data['demand']
    supply = data['supply']
    mutations = []
    for i in range(len(demand)):
        if demand[i] > supply[i]:
            mutations.append({'type': 'adjust_supply', 'index': i, 'new_value': demand[i]})
        else:
            mutations.append({'type': 'reduce_demand', 'index': i, 'new_value': supply[i]})
    return mutations

def apply_mutations(data, mutations):
    for mutation in mutations:
        if mutation['type'] == 'adjust_supply':
            data['supply'][mutation['index']] = mutation['new_value']
        elif mutation['type'] == 'reduce_demand':
            data['demand'][mutation['index']] = mutation['new_value']
    return data

def main():
    initial_data = {'demand': [100, 200, 150, 300], 'supply': [120, 180, 160, 310]}
    mutations = optimize_inventory(initial_data)
    final_data = apply_mutations(initial_data, mutations)
    print(final_data)
main()