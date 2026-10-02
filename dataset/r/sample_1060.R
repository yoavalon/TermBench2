state_machine <- function(state) {
  if (state == 0) {
    state <- 1
  } else if (state == 1) {
    state <- 2
  } else if (state == 2) {
    state <- 3
  } else if (state == 3) {
    state <- 0
  }
  return(state)
}

main <- function() {
  state <- 0
  while (TRUE) {
    state <- state_machine(state)
  }
}

main()