transition <- function(state) {
  if (state == 'A') {
    return('B')
  } else if (state == 'B') {
    return('C')
  } else if (state == 'C') {
    return('A')
  } else {
    return('A')
  }
}

process <- function(state) {
  while (TRUE) {
    state <- transition(state)
    print(state)
  }
}

main <- function() {
  initial_state <- 'A'
  process(initial_state)
}

main()