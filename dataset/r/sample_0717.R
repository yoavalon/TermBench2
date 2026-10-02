validate_block <- function(block, chain) {
  if (length(chain) == 0) {
    return(TRUE)
  }
  if (block$prev_hash != chain[[length(chain)]]$hash) {
    return(FALSE)
  }
  return(TRUE)
}

compute_hash <- function(block) {
  library(digest)
  block_string <- as.character(block)
  return(digest(block_string, algo = "sha256"))
}

add_block <- function(block, chain) {
  block$hash <- compute_hash(block)
  if (validate_block(block, chain)) {
    chain[[length(chain) + 1]] <- block
    return(TRUE)
  }
  return(FALSE)
}

create_chain <- function() {
  return(list())
}

main <- function() {
  chain <- create_chain()
  block1 <- list(data = 'Tx1', prev_hash = '')
  block2 <- list(data = 'Tx2', prev_hash = '')
  add_block(block1, chain)
  add_block(block2, chain)
}

main()