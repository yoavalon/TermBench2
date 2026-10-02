def state_machine(state, steps):
    if not steps:
        return state
    if state == 'open':
        return state_machine('close', steps - 1)
    if state == 'close':
        return state_machine('open', steps - 1)

def main():
    print(state_machine('open', 5))
main()