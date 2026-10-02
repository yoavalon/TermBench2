ledger_update <- function(balance, transaction) {
  precision <- 1e-10
  if (abs(transaction) < precision) {
    return(balance)
  }
  return(balance + transaction)
}

consensus_mechanism <- function(data) {
  processed_data <- c()
  for (entry in data) {
    processed_data <- c(processed_data, ledger_update(0, entry))
  }
  return(processed_data)
}

main <- function() {
  data <- c(0.1, 0.2, -0.3, 0.4, -0.1, 0.2)
  while (TRUE) {
    data <- consensus_mechanism(data)
  }
}

main()