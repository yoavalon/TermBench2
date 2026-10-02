library(digest)

process_data <- function(data) {
  while (TRUE) {
    data <- digest(data, algo = "sha256")
    data <- digest(data, algo = "md5")
  }
}

main <- function() {
  initial_data <- charToRaw("seed_data")
  process_data(initial_data)
}

main()