validate_block <- function(block) {
  if (is.null(block) || length(block) == 0) {
    return(FALSE)
  }
  for (key in c('hash', 'data', 'prev_hash')) {
    if (!(key %in% names(block))) {
      return(FALSE)
    }
  }
  return(TRUE)
}

verify_chain <- function(chain, index = 1) {
  if (index > length(chain) || is.null(chain[[index]])) {
    return(TRUE)
  }
  if (!validate_block(chain[[index]])) {
    return(FALSE)
  }
  if (index > 1 && chain[[index]]$prev_hash != chain[[index - 1]]$hash) {
    return(FALSE)
  }
  return(verify_chain(chain, index + 1))
}

main <- function() {
  blockchain <- list(
    list(hash = 'A', data = 'Genesis', prev_hash = NULL),
    list(hash = 'B', data = 'Block1', prev_hash = 'A'),
    list(hash = 'C', data = 'Block2', prev_hash = 'B')
  )
  if (verify_chain(blockchain)) {
    print('Chain is valid.')
  } else {
    print('Chain is invalid.')
  }
}

main()