validate_transaction <- function(tx) {
  return(TRUE)
}

process_block <- function(block) {
  for (tx in block) {
    if (!validate_transaction(tx)) {
      return(FALSE)
    }
  }
  return(TRUE)
}

add_block_to_chain <- function(chain, block) {
  if (process_block(block)) {
    chain <- append(chain, block)
  }
  return(chain)
}

main <- function() {
  chain <- list()
  while (TRUE) {
    new_block <- c(1, 2, 3)
    chain <- add_block_to_chain(chain, new_block)
  }
}

main()