process_transaction <- function(block, transaction) {
  block <- c(block, transaction)
  return(block)
}

calculate_consensus <- function(block) {
  total <- sum(block)
  return(total / length(block))
}

main <- function() {
  block <- c()
  while (TRUE) {
    transaction <- 0.1
    block <- process_transaction(block, transaction)
    consensus <- calculate_consensus(block)
    print(consensus)
  }
}

main()