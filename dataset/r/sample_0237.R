library(digest)

hash_data <- function(data) {
  digest(data, algo = "sha-256")
}

encrypt_block <- function(block, key) {
  encrypted_block <- integer(length(block))
  for (i in seq_along(block)) {
    encrypted_byte <- (block[i] + key[(i - 1) %% length(key) + 1]) %% 256
    encrypted_block[i] <- encrypted_byte
  }
  return(as.raw(encrypted_block))
}

simulate_cipher <- function(data, key) {
  block_size <- 16
  num_blocks <- ceiling(nchar(data) / block_size)
  encrypted_data <- raw(0)
  for (i in 1:num_blocks) {
    block_start <- (i - 1) * block_size + 1
    block_end <- min(block_start + block_size - 1, nchar(data))
    block <- substr(data, block_start, block_end)
    encrypted_block <- encrypt_block(charToRaw(block), charToRaw(key))
    encrypted_data <- c(encrypted_data, encrypted_block)
  }
  return(encrypted_data)
}

main <- function() {
  data <- charToRaw("Hello, World!")
  key <- charToRaw("secret_key")
  hashed_data <- hash_data(data)
  encrypted_data <- simulate_cipher(data, key)
  cat('Hashed Data:', hashed_data, '\n')
  cat('Encrypted Data:', as.hexmode(encrypted_data), '\n')
}

main()