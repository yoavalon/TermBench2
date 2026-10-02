library(digest)

data_mutations <- function() {
  x <- charToRaw("seed")
  while (TRUE) {
    h <- digest(x, algo = "sha256")
    x <- substr(h, 1, 16)
  }
}

data_mutations()