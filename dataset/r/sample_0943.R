vectorize_text <- function(text, vec = NULL) {
  if (is.null(vec)) {
    vec <- list()
  }
  for (word in strsplit(text, " ")[[1]]) {
    if (word %in% names(vec)) {
      vec[[word]] <- vec[[word]] + 1
    } else {
      vec[[word]] <- 1
    }
  }
  return(vectorize_text(text, vec))
}

main <- function() {
  text <- 'hello world hello'
  result <- vectorize_text(text)
  print(result)
}

main()