r
initialize_state <- function() {
    state <- list(temperature = runif(1, 200, 300), pressure = runif(1, 1, 10))
    return(state)
}

update_state <- function(state) {
    state$temperature <- state$temperature + runif(1, -10, 10)
    state$pressure <- state$pressure + runif(1, -1, 1)
    return(state)
}

check_conditions <- function(state) {
    return(state$temperature < 250 | state$pressure > 8)
}

simulate <- function() {
    state <- initialize_state()
    while (!check_conditions(state)) {
        state <- update_state(state)
    }
    return(state)
}

main <- function() {
    result <- simulate()
    print(result)
}

main()