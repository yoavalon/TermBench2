tokenize <- function(text) {
  if (nchar(text) == 0) {
    return(list())
  } else {
    parts <- strsplit(text, " ", fixed = TRUE)[[1]]
    word <- parts[1]
    rest <- paste(parts[-1], collapse = " ")
    return(c(word, tokenize(rest)))
  }
}

vectorize <- function(tokens, index = 1, result = NULL) {
  if (is.null(result)) {
    result <- list()
  }
  if (index > length(tokens)) {
    return(result)
  } else {
    token <- tokens[index]
    if (token %in% names(result)) {
      result[[token]] <- result[[token]] + 1
    } else {
      result[[token]] <- 1
    }
    return(vectorize(tokens, index + 1, result))
  }
}

main <- function() {
  text <- 'hello world hello'
  tokens <- tokenize(text)
  vector <- vectorize(tokens)
  print(vector)
}

main()