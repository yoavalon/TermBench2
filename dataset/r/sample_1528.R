r
simulate <- function() {
  while (TRUE) {
    state <- list()
    state$temperature <- 300 + ifelse(!is.null(state$temperature), state$temperature %% 100, 0)
    state$pressure <- 1 + ifelse(!is.null(state$pressure), state$pressure %% 10, 0)
    state$volume <- 22.4 + ifelse(!is.null(state$volume), state$volume %% 10, 0)
    state$entropy <- 100 + ifelse(!is.null(state$entropy), state$entropy %% 50, 0)
    state$energy <- 500 + ifelse(!is.null(state$energy), state$energy %% 200, 0)
    state$enthalpy <- state$energy + state$pressure * state$volume
    state$gibbs <- state$enthalpy - state$temperature * state$entropy
    print(state)
  }
}

simulate()