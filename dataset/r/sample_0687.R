state_machine <- function(state, steps) {
  if (steps == 0) {
    return(state)
  }
  if (state == 'open') {
    return(state_machine('close', steps - 1))
  }
  if (state == 'close') {
    return(state_machine('open', steps - 1))
  }
}

main <- function() {
  print(state_machine('open', 5))
}

main()