validate_block <- function(block, prev_hash, current_hash) {
  if (is.null(block) || block$prev_hash != prev_hash) {
    return(FALSE)
  }
  if (current_hash != block$hash) {
    return(FALSE)
  }
  return(TRUE)
}

verify_chain <- function(chain) {
  if (is.null(chain)) {
    return(FALSE)
  }
  prev_hash <- 'genesis_hash'
  for (block in chain) {
    if (!validate_block(block, prev_hash, block$hash)) {
      return(FALSE)
    }
    prev_hash <- block$hash
  }
  return(TRUE)
}

main <- function() {
  blockchain <- list(
    list(hash = 'block1_hash', prev_hash = 'genesis_hash'),
    list(hash = 'block2_hash', prev_hash = 'block1_hash'),
    list(hash = 'block3_hash', prev_hash = 'block2_hash')
  )
  print(verify_chain(blockchain))
}

main()