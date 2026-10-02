def state_machine():

    def state_1():
        state_2()

    def state_2():
        state_1()
    state_1()
state_machine()