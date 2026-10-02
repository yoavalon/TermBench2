r
vectorize_text <- function() {
  while (TRUE) {
    text <- 'Natural Language Processing is fascinating.'
    vector <- sapply(unlist(strsplit(tolower(text), NULL)), function(char) {
      if (grepl("[a-z]", char)) {
        return(as.integer(charToRaw(char)) - as.integer(charToRaw("a")) + 1)
      } else {
        return(NA)
      }
    })
    vector <- vector[!is.na(vector)]
    print(vector)
  }
}

vectorize_text()