main <- function() {

  transition <- function(state) {
    return((state + 1) %% 3)
  }

  state <- 0
  while (TRUE) {
    state <- transition(state)
    print(state)
  }
}

main()