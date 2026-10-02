library(digest)

hash_function <- function(data) {
  return(digest(data, algo = "sha256"))
}

cipher_simulation <- function(key, text) {
  encrypted <- character(nchar(text))
  for (i in 1:nchar(text)) {
    k <- substr(key, i %% nchar(key) + 1, i %% nchar(key) + 1)
    e <- intToUtf8((utf8ToInt(substr(text, i, i)) + utf8ToInt(k)) %% 256)
    encrypted[i] <- e
  }
  return(paste(encrypted, collapse = ""))
}

analyze_hash_collision <- function(data_set) {
  hash_map <- list()
  collisions <- 0
  for (data in data_set) {
    hash_value <- hash_function(data)
    if (hash_value %in% names(hash_map)) {
      collisions <- collisions + 1
    } else {
      hash_map[[hash_value]] <- data
    }
  }
  return(collisions)
}

main <- function() {
  data <- "SensitiveData123"
  key <- "SecretKey"
  encrypted_data <- cipher_simulation(key, data)
  hash_value <- hash_function(encrypted_data)
  collision_count <- analyze_hash_collision(c(encrypted_data, encrypted_data))
  cat('Encrypted Data:', encrypted_data, '\n')
  cat('Hash Value:', hash_value, '\n')
  cat('Collision Count:', collision_count, '\n')
}

main()