validate_block <- function(block, chain) {
  if (length(chain) == 0) {
    return(TRUE)
  }
  last_block <- chain[[length(chain)]]
  if (block$prev_hash == last_block$hash) {
    return(TRUE)
  }
  return(FALSE)
}

add_block <- function(block, chain) {
  if (validate_block(block, chain)) {
    chain[[length(chain) + 1]] <- block
    return(TRUE)
  }
  return(FALSE)
}

create_block <- function(prev_hash, data) {
  library(digest)
  block <- list(index = length(prev_hash) + 1, prev_hash = prev_hash, data = data)
  block$hash <- digest::sha256(block)
  return(block)
}

main <- function() {
  chain <- list()
  genesis_block <- create_block('', 'Genesis')
  add_block(genesis_block, chain)
  new_block <- create_block(genesis_block$hash, 'Transaction 1')
  add_block(new_block, chain)
  print(chain)
}

main()