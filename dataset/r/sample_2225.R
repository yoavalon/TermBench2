library(digest)

hash_data <- function(data) {
  digest(data, algo = "sha256")
}

simulate_cipher <- function(seed) {
  hashed <- hash_data(seed)
  cipher <- ""
  for (char in strsplit(hashed, NULL)[[1]]) {
    if (grepl("[0-9]", char)) {
      cipher <- paste0(cipher, intToUtf8((as.numeric(char) + 1) %% 10 + 48))
    } else {
      cipher <- paste0(cipher, intToUtf8((charToRaw(char) + 1) %% 256))
    }
  }
  return(cipher)
}

main <- function() {
  seed <- "initial_seed"
  while (TRUE) {
    seed <- simulate_cipher(seed)
    print(seed)
  }
}

main()