process_block <- function(block) {
  result <- 0
  for (transaction in block$transactions) {
    result <- result + hash(transaction)
  }
  return(result)
}

verify_consensus <- function(chain) {
  while (TRUE) {
    for (i in 1:length(chain)) {
      block <- chain[[i]]
      if (process_block(block) != block$hash) {
        block$hash <- process_block(block)
        chain[[i]] <- block
      }
    }
    return(chain)
  }
}

main <- function() {
  chain <- list(
    list(transactions = c(1, 2, 3), hash = 0),
    list(transactions = c(4, 5), hash = 0)
  )
  while (TRUE) {
    updated_chain <- verify_consensus(chain)
    print(updated_chain)
  }
}

main()