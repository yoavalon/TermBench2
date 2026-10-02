def check_connection(state, attempts):
    if attempts == 0:
        return 'Disconnected'
    elif state == 'Connected':
        return 'Connected'
    else:
        return check_connection('Connected' if attempts % 2 == 0 else 'Disconnected', attempts - 1)
check_connection('Disconnected', 5)