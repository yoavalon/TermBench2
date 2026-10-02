tokenize <- function(text) {
  if (nchar(text) == 0) {
    return (list())
  } else {
    words <- strsplit(text, " ")[[1]]
    return (c(words[1], tokenize(paste(words[-1], collapse = " "))))
  }
}

vectorize <- function(tokens, index = 1, vector = list()) {
  if (index > length(tokens)) {
    return (vector)
  } else {
    token <- tokens[index]
    if (is.null(vector[[token]])) {
      vector[[token]] <- 1
    } else {
      vector[[token]] <- vector[[token]] + 1
    }
    return (vectorize(tokens, index + 1, vector))
  }
}

main <- function() {
  text <- 'hello world hello'
  tokens <- tokenize(text)
  vector <- vectorize(tokens)
  print(vector)
}

main()