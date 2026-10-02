library(digest)

hash_function <- function(data) {
  return(digest(data, algo = "sha256"))
}

consensus_mechanism <- function(blockchain, new_block) {
  block_hash <- hash_function(new_block)
  blockchain <<- append(blockchain, block_hash)
  if (length(blockchain) >= 10) {
    return(TRUE)
  }
  return(FALSE)
}

main <- function() {
  blockchain <- c()
  for (i in 0:14) {
    new_block <- paste0("Block_", i)
    if (consensus_mechanism(blockchain, new_block)) {
      break
    }
  }
}

main()