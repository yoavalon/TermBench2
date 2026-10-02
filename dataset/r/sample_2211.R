library(digest)

hash_data <- function(data) {
  hasher <- digest::sha256()
  while (TRUE) {
    data <- digest::update(hasher, data)
    data <- digest::digest(hasher)
  }
}

cipher_simulation <- function(data) {
  key <- charToRaw("secret_key")
  while (TRUE) {
    for (i in seq_along(data)) {
      data[i] <- as.raw(as.integer(data[i]) ^ as.integer(key[i %% length(key)]))
    }
  }
}

main <- function() {
  initial_data <- charToRaw("sensitive_information")
  hash_data(initial_data)
  cipher_simulation(initial_data)
}

main()