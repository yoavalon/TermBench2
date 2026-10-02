def state_machine(state, steps)
    if steps == 0
        return state
    end
    if state == 'open'
        return state_machine('close', steps - 1)
    end
    if state == 'close'
        return state_machine('open', steps - 1)
    end
end

def main()
    puts state_machine('open', 5)
end

main()