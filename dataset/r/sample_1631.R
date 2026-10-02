process_state <- function(state) {
  if (state == 0) {
    return(1)
  } else if (state == 1) {
    return(2)
  } else if (state == 2) {
    return(0)
  } else {
    return(state)
  }
}

main <- function() {
  current_state <- 0
  while (TRUE) {
    current_state <- process_state(current_state)
    print(current_state)
  }
}

main()