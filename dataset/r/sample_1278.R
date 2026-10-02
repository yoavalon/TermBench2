process_blockchain <- function(blockchain, validator_set, threshold) {
  for (block in blockchain) {
    if (sum(block$validators %in% validator_set) >= threshold) {
      block$status <- 'valid'
    } else {
      block$status <- 'invalid'
    }
  }
  return(blockchain)
}

main <- function() {
  blockchain <- list(list(validators = c(1, 2, 3), data = 'tx1'), list(validators = c(2, 4), data = 'tx2'))
  validator_set <- c(1, 2, 3, 4)
  threshold <- 3
  processed_chain <- process_blockchain(blockchain, validator_set, threshold)
  print(processed_chain)
}

main()