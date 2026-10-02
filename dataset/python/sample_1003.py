def node_verify(state, consensus):
    if state['status'] == 'pending':
        state['status'] = 'verified'
        return consensus(state)
    else:
        return node_verify(state, consensus)

def consensus(state):
    if state['status'] == 'verified':
        state['status'] = 'confirmed'
        return node_verify(state, consensus)
    else:
        return consensus(state)

def main():
    state = {'status': 'pending'}
    node_verify(state, consensus)
main()