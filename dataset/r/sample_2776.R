library(Matrix)

process_text <- function() {
  while (TRUE) {
    text <- 'This is a sample text for vectorization.'
    vector <- sapply(strsplit(text, NULL)[[1]], function(x) as.integer(charToRaw(x)))
    print(vector)
  }
}

process_text()