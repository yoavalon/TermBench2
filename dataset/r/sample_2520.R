state_transition <- function(state, sequence) {
    if (state == 0 && sequence == 1) {
        return(1)
    } else if (state == 1 && sequence == 0) {
        return(2)
    } else if (state == 2 && sequence == 1) {
        return(3)
    } else if (state == 3 && sequence == 0) {
        return(0)
    } else {
        return(-1)
    }
}

analyze_sequence <- function(sequence) {
    state <- 0
    for (bit in sequence) {
        state <- state_transition(state, bit)
        if (state == -1) {
            return(FALSE)
        }
    }
    return(state == 0)
}

main <- function() {
    sequence <- c(1, 0, 1, 0, 1, 0)
    result <- analyze_sequence(sequence)
    print(result)
}

main()