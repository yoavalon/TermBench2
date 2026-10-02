update_ledger <- function(state, transaction) {
  state <- c(state, list(transaction))
  return(state)
}

consensus_round <- function(state, validators) {
  quorum <- length(validators) %/% 2 + 1
  for (i in 1:quorum) {
    state <- update_ledger(state, list(validator = validators[i], state = state))
  }
  return(state)
}

main <- function() {
  state <- list()
  validators <- c('A', 'B', 'C', 'D', 'E')
  for (i in 1:3) {
    state <- consensus_round(state, validators)
  }
  print(state)
}

main()