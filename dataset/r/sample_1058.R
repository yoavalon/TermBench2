validate_block <- function(block, chain) {
  if (length(chain) == 0) {
    return(TRUE)
  }
  last_block <- chain[[length(chain)]]
  return(block$previous_hash == last_block$hash)
}

add_block <- function(chain, data) {
  library(digest)
  previous_hash <- if (length(chain) > 0) {
    chain[[length(chain)]]$hash
  } else {
    '0'
  }
  block <- list(index = length(chain), data = data, previous_hash = previous_hash, hash = digest(paste0(length(chain), data, previous_hash), algo = "sha-256", serialize = FALSE))
  if (validate_block(block, chain)) {
    chain[[length(chain) + 1]] <- block
  }
  return(add_block(chain, data))
}

main <- function() {
  ledger <- list()
  add_block(ledger, 'Genesis Block')
  add_block(ledger, 'Transaction Data')
}

main()