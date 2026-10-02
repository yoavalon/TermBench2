update_ledger <- function(data, node) {
  for (key in names(data)) {
    data[[key]] <- data[[key]] + node[[key]]
  }
  return(data)
}

simulate_consensus <- function(nodes) {
  ledger <- setNames(rep(0, length(nodes[[1]])), names(nodes[[1]]))
  for (node in nodes) {
    ledger <- update_ledger(ledger, node)
  }
  return(ledger)
}

main <- function() {
  nodes <- list(list(A = 1, B = 2, C = 3), list(A = 4, B = 5, C = 6), list(A = 7, B = 8, C = 9))
  while (TRUE) {
    ledger <- simulate_consensus(nodes)
    print(ledger)
  }
}

main()