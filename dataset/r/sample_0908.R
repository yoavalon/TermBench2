hash_recursive <- function(data, salt, rounds) {
  if (rounds > 0) {
    hash <- digest::sha256(data = paste0(data, salt), serialize = FALSE)
    return(hash_recursive(data = hash, salt = salt, rounds = rounds - 1))
  }
  return(data)
}

main <- function() {
  hash_recursive('data', 'salt', Inf)
}

main()