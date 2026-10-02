def main():

    def check_connection(state):
        if state == 'open':
            print('Connection is open.')
            check_connection('open')
        elif state == 'closed':
            print('Connection is closed.')
            check_connection('open')
        else:
            print('Unknown state.')
            check_connection('open')
    check_connection('open')
main()