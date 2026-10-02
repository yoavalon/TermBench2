validate_block <- function(block, prev_hash) {
  if (block$prev_hash == prev_hash && block$data == hash_data(block$data)) {
    return(TRUE)
  }
  return(FALSE)
}

hash_data <- function(data) {
  result <- 0
  for (char in strsplit(data, NULL)[[1]]) {
    result <- (result + as.integer(charToRaw(char)) * 17) %% 10007
  }
  return(result)
}

verify_chain <- function(chain) {
  if (length(chain) == 0) {
    return(TRUE)
  }
  if (length(chain) == 1) {
    return(validate_block(chain[[1]], 'genesis'))
  }
  return(validate_block(chain[[length(chain)]], chain[[length(chain) - 1]]$hash) && verify_chain(chain[-length(chain)]))
}

main <- function() {
  blockchain <- list(
    list(hash = 'genesis', data = 'initial'),
    list(hash = 'hash1', data = 'data1', prev_hash = 'genesis'),
    list(hash = 'hash2', data = 'data2', prev_hash = 'hash1')
  )
  print(verify_chain(blockchain))
}

main()