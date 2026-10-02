library(digest)

hash_mutations <- function() {
  a <- charToRaw("seed")
  while (TRUE) {
    a <- digest(a, algo = "sha256", file = NULL)
    cat(as.character(intToHex(as.integer(a))), "\n")
  }
}

hash_mutations()